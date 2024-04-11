#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const int MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int t,a,b,sz,tmp;
string s;
pii tree[4*MAX],res;

void build(int id,int le,int ri){
	if(le==ri){
		if(s[le]=='(')tree[id].fi = 1;
		else tree[id].se = 1;
		return;
	}
	int mid = (le+ri)/2;
	build(id*2,le,mid);
	build(id*2+1,mid+1,ri);
	tmp = tree[id*2].fi-tree[id*2+1].se;
	tree[id] = {max(tmp,0)+tree[id*2+1].fi,max(-tmp,0)+tree[id*2].se};
	return;
}

pii query(int id,int le,int ri,int l,int r){
	if(le>r || ri<l)return {0,0};
//	cout<<le<<" "<<ri<<" "<<l<<" "<<r<< endl;
	if(le>=l && ri<=r)return tree[id];
	int mid = (le+ri)/2;
	pii t1 = query(id*2,le,mid,l,r);
	pii t2 = query(id*2+1,mid+1,ri,l,r);
	tmp = t1.fi-t2.se;
//	cout<<le<<" "<<mid<<" "<<ri<<" "<<l<<" "<<r<< endl;
//	cout<<le<<" "<<ri<<" "<<tmp<<" --- "<<t1.fi<<" "<<t1.se<<" --- "<<t2.fi<<" "<<t2.se<<endl;
//	cout<<"ret = "<<max(tmp,0)+t2.fi<<" "<<max(-tmp,0)+t1.se<<endl;
	return {max(tmp,0)+t2.fi,max(-tmp,0)+t1.se};
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    build(1,0,sz);
    cin>>t;
    while(t--){
    	cin>>a>>b;
    	res = query(1,0,sz,a-1,b-1);
//    	cout<<res.fi<<" "<<res.se<<endl;
    	cout<<b-a+1-res.fi-res.se<<endl;
	}
    return 0;
}
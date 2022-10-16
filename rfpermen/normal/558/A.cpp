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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);


int n,a,b,k,q,a1,a2,id;
pii x[105],y[105];

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>a>>b;
    	if(a<0)x[++k] = {-a,b};
    	else y[++q] = {a,b};
	}
	sort(x+1,x+1+k);
	sort(y+1,y+1+q);
	id = 1;
	while(id<=k){
		a1+=x[id].se;
		if(id>q)break;
		a1+=y[id].se;
		id++;
	}
	id = 1;
	while(id<=q){
		a2+=y[id].se;
		if(id>k)break;
		a2+=x[id].se;
		id++;
	}
	cout<<max(a1,a2);
    return 0;
}
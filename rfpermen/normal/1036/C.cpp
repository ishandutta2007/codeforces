#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define endl "\n"
const ll MAX=3e5+5;
const int MOD=1000000000 + 7;
const ll INF=2e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

ll n,le,ri,mid,a1,a2,a,b,sz;
vector<ll> v;

void dfs(unsigned ll num,int cs){
	if(num>1e18)return;
	v.pb(num);
	dfs(10*num,cs);
	if(cs==3)return;
	rep(i,1,9)dfs(10*num+i,cs+1);
}

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,9)dfs(i,1);
    sort(v.begin(),v.end());
    sz = v.size()-1;
    cin>>n;
    while(n--){
    	cin>>a>>b;
    	le = 0, ri = sz;
    	while(le<=ri){
    		mid = (le+ri)/2;
    		if(v[mid]>=a)a1 = mid, ri = mid-1;
    		else le = mid+1;
		}
    	le = 0, ri = sz;
    	while(le<=ri){
    		mid = (le+ri)/2;
    		if(v[mid]<=b)a2 = mid, le = mid+1;
    		else ri = mid-1;
		}
		cout<<a2-a1+1<<endl;
	}
    return 0;
}
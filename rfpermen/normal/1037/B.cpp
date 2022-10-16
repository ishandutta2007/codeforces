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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=2e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,-1,0,1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

ll n,x[MAX],y,a,b,cnt,res,sz;
string s,t;

int main(){
//	cout<<fixed<<setprecision(3);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>y;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    a = (n+1)/2;
    if(x[a]==y)return cout<<0,0;
    if(x[a]<y){
    	while(a<=n && x[a]<y){
    		res+=y-x[a];
    		a++;
		}
	}
	else {
    	while(a>0 && x[a]>y){
    		res+=x[a]-y;
    		a--;
		}
	}
	cout<<res<<endl;
    return 0;
}
#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll ans,n,m,x,d,pl,ng,pref[MAX];
double N;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,2,n)pref[i] = i-1;
    rep(i,2,n)pl+=pref[i];
    memset(pref,0,sizeof pref);
    rep(i,(n+1)/2,n)pref[i] = i-(n+1)/2;
    rap(i,(n+1)/2,1)pref[i] = (n+1)/2-i;
    rep(i,1,n)ng+=pref[i];
    N=n;
    while(m--){
    	cin>>x>>d;
    	ans+=x*n;
    	ans+=max(d*ng,d*pl);
	}
	cout<<(double)ans/N<<endl;
    return 0;
}
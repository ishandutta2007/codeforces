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
const ll MAX=1e5;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,m,cnt,ttl;
vector<pii> ans;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(m<n-1)return cout<<"Impossible",0;
    rep(i,2,n)ans.pb({1,i}), ttl++;
    rep(i,2,n){
    	if(ttl==m)break;
    	rep(j,i+1,n){
    		if(ttl==m)break;
    		if(__gcd(i,j)==1)ans.pb({i,j}), ttl++;
		}
	}
	if(ttl<m)return cout<<"Impossible",0;
	cout<<"Possible\n";
	for(auto i:ans)cout<<i.fi<<" "<<i.se<<endl;
    return 0;
}
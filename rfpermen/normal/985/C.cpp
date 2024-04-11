#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
//#define endl "\n"
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll m,n,k,l,x[MAX],mn,hit,pos,ans;

int main(){
    //cout<<fixed<<setprecision(3);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>k>>l;
    n=m*k;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    mn=x[1];
    rep(i,1,n){
    	if(x[i]-mn>l)break;
    	hit++;
	}
	if(hit<m)return cout<<0,0;
	//cout<<hit<<endl;
	pos=1;
	while(hit-k>=m-1 && m){
		hit-=k;
		m--;
		ans+=x[pos];
		pos+=k;
	}
	rap(i,hit+pos-1,pos+hit-m+1)ans+=x[i];
	//cout<<ans<<endl;
	if(m)ans+=x[pos];
	//cout<<hit+pos<<endl;
	cout<<ans<<endl;
    return 0;
}
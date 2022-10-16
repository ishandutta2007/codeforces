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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,m,k,mn,md,x[105][105],ans,cnt,y[MAX],med;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    mn = x[1][1];
    md = mn%k;
    rep(i,1,n)rep(j,1,m){
    	mn = min(mn,x[i][j]);
    	if(md!=x[i][j]%k)return cout<<-1,0;
	}
	rep(i,1,n)rep(j,1,m)y[++cnt] = x[i][j];
	sort(y+1,y+1+cnt);
	med = (cnt+1)/2;
	rep(i,1,cnt){
		ans+= abs(y[i]-y[med])/k;
	}
	cout<<ans<<endl;
    return 0;
}
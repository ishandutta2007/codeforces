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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,a,b,x[MAX],ans;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ans =MAX;
    rep(i,1,n){
    	cin>>a>>b;
    	if(b<a)swap(a,b);
    	x[a]++, x[b+1]--;
	}
	rep(i,1,1000)x[i]+=x[i-1];
	rep(i,0,1000){
		//cout<<x[i]<<endl;
		if(x[i]!=n)continue;
		ans = min(ans,abs(i-m));
	}
	if(ans==MAX)cout<<-1;
	else cout<<ans<<endl;
    return 0;
}
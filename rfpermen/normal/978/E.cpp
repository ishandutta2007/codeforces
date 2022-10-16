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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,m,mn,mx,cur,y,ans;
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>cur;mn=min((ll)0,cur), mx=max((ll)0,cur), n--;
	while(n--){
		cin>>y;
		cur+=y;
		mn=min(mn,cur), mx=max(mx,cur);
	}
	ans=mx-min((ll)0,mn);
	//cout<<mn<<" "<<mx<<endl;
	cout<<max((ll)0,m+1-ans)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=100005;
const int MOD=1000000000 + 7;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,k,ans,cnt;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	if(k==1){
		cout<<1<<endl;
		return 0;
	}
	ans=1;
	if(k>=2){
		cnt=1;
		rap(i,n,n-2+1)cnt*=i;cnt/=2;
		ans+=cnt;
	}
	if(k>=3){
		cnt=1;
		rap(i,n,n-3+1)cnt*=i;cnt/=3;
		ans+=cnt;
	}
	if(k==4){
		cnt=1;
		rap(i,n,n-4+1)cnt*=i;cnt*=9;cnt/=24;
		ans+=cnt;
	}
	cout<<ans<<endl;
	return 0;
}
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
ll n,m,x[1000],ans,all,cnt,lel;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>x[i];
	rep(i,1,n){
		all+=x[i];
		//cout<<all<<endl;
		if(cnt<m){
			cnt+=min((ll)8,all), lel=min((ll)8,all),ans++;
			all-=lel;
			//cout<<cnt<<endl;
		}
		else {
			break;
		}
	}
	if(cnt<m)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
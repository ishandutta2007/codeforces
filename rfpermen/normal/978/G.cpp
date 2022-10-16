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
const ll MAX=105;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n,m,s[MAX],d[MAX],c[MAX],ans[MAX],mx,dy;
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,m)cin>>s[i]>>d[i]>>c[i];
	rep(i,1,n){
		dy=0, mx=-100000;
		rep(j,1,m){
			if(s[j]>i)continue;
			if(d[j]<i)continue;
			if(d[j]==i){
				if(c[j]){
					cout<<-1<<endl;
					return 0;
				}
				dy=m+1; break;
			}
			if(c[j]==0)continue;
			if(mx<c[j]-d[j])mx=c[j]-d[j], dy=j;
		}
		//cout<<dy<<endl;
		c[dy]--;
		ans[i]=dy;
	}
	rep(i,1,n)cout<<ans[i]<<" ";
	cout<<endl;
    return 0;
}
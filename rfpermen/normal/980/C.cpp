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
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,k,x[MAX],key[300],st,st2,en,ans[MAX],fo;

int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;rep(i,0,299)key[i]=-1;
	rep(i,1,n){
		cin>>x[i];
		if(key[x[i]]!=-1){
			ans[i]=key[x[i]];
			continue;
		}
		fo=0;
		st=max((ll)0,x[i]-k+1);
		//cout<<st<<endl;
		rep(j,st,x[i]){
			if(key[j]==-1){
				rep(a,j,x[i])key[a]=j;
				ans[i]=j;
				break;
			}
			if(x[i]-key[j]<k){
				rep(a,j+1,x[i])key[a]=key[j];
				ans[i]=key[j];
				break;
			}
		}
	}
	rep(i,1,n){
		cout<<ans[i];
		if(i==n)cout<<endl;
		else cout<<" ";
	}
    return 0;
}
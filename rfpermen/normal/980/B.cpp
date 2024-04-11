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
const ll MAX=200005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,m,k,nw;
char x[6][200];

int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>m>>k;n=4;
	rep(i,1,n)rep(j,1,m)x[i][j]='.';
	cout<<"YES"<<endl;
	rep(i,2,n-1){
		nw=2;
		while(1){
			//cout<<"lala"<<endl;
			if(k==1){
				k--;
				x[i][(m+1)/2]='#';
			}
			if(k==0)break;
			if(nw==(m+1)/2){
				x[i][nw]='#';k--;
				break;
			}
			x[i][nw]='#';
			x[i][m-nw+1]='#';
			nw++;
			k-=2;
		}
	}
	rep(i,1,n){
		rep(j,1,m)cout<<x[i][j];
		cout<<endl;
	}
    return 0;
}
#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
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
const ll MAX=100010;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n,k,x[105][105],st,y,z,mx;
char gr[105][105];
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)rep(j,1,n)cin>>gr[i][j];
    rep(i,1,n)rep(j,1,n-k+1){
    	st=0;
    	rep(a,j,j+k-1){
    		if(gr[i][a]=='#')break;
    		else if(a==j+k-1)st=1;
		}
		if(st)rep(a,j,j+k-1){
    		x[i][a]++;
		}
	}
	rep(i,1,n)rep(j,1,n-k+1){
    	st=0;
    	rep(a,j,j+k-1){
    		if(gr[a][i]=='#')break;
    		if(a==j+k-1)st=1;
		}
		if(st)rep(a,j,j+k-1){
    		x[a][i]++;
		}
	}
	rep(i,1,n)rep(j,1,n){
		if(mx<x[i][j])mx=x[i][j], y=i, z=j;
	}
	/*rep(i,1,n){
		rep(j,1,n)cout<<x[i][j];
		cout<<endl;
	}*/
	cout<<max(1,y)<<" "<<max(1,z)<<endl;
    return 0;
}
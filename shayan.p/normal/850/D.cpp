// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<bool,bool> pbl;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

const int M1=33,M2=63,M3=63*33;

pbl dp[M1+40][M2+40][M3+40];
int a[M1],B=-1,C=-1;
int adj[M2][M2];
vector<pii>dg;

int main(){
    int m;scanf("%d",&m);
    for(int i=0;i<m;i++)
	scanf("%d",&a[i]);
    sort(a,a+m);
    dp[0][0][0]={1,0};
    for(int i=0;i<m;i++){
	for(int j=0;j<M2;j++){
	    for(int k=(j*(j-1))/2;k<M3;k++){
		if(dp[i][j][k].F){
		    dp[i+1][j+1][k+a[i]]={1,1};
		    dp[i][j+1][k+a[i]]={1,0};
		}
	    }
	}
    }
    for(int j=0;j<M2;j++){
	for(int k=0;k<M3;k++){
	    if(B==-1 && dp[m][j][k].F && j*(j-1)==2*k)
		B=j,C=k;
	}
    }
    int n=B;
    if(n==-1){
	printf("=\n");
	return 0;
    }
    for(;B>0;B--){
	int D=(dp[m][B][C].S?a[--m]:a[m]);
	C-=D;
	dg.PB({D,B-1});
    }
    while(!dg.empty()){
	sort(dg.begin(),dg.end());
	for(int j=1;j<sz(dg);j++){
	    if(dg[0].F>0){
		adj[dg[0].S][dg[j].S]=1;
		dg[0].F--;
	    }
	    else{
		adj[dg[j].S][dg[0].S]=1;
		dg[j].F--;
	    }
	}
	swap(dg[0],dg[sz(dg)-1]);
	dg.POB();
    }
    printf("%d\n",n);
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	    printf("%d",adj[i][j]);
	printf("\n");
    }
    return 0;
}
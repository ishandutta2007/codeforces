// Faster!

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1010,inf=1e9;

string s[maxn];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ds[3][maxn][maxn];
int arr[3][3];
queue<pii>q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    memset(ds,-1,sizeof ds);
    for(char ch='1';ch<='3';ch++){
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		if(s[i][j]==ch) q.push({i,j}),ds[ch-'1'][i][j]=0;
	    }
	}
	while(sz(q)){
	    pii p=q.front();
	    q.pop();
	    for(int w=0;w<4;w++){
		int X=p.F+dx[w],Y=p.S+dy[w];
		if(X>=0 && Y>=0 && X<n && Y<m && s[X][Y]!='#' && ds[ch-'1'][X][Y]==-1){
		    ds[ch-'1'][X][Y]=1+ds[ch-'1'][p.F][p.S];
		    q.push({X,Y});
		}
	    }
	}
    }
    memset(arr,-1,sizeof arr);
    for(int a=0;a<3;a++){
	for(int b=0;b<3;b++){
	    if(a==b) continue;
	    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		    if(s[i][j]=='1'+b && ds[a][i][j]!=-1){
			if(arr[a][b]==-1) arr[a][b]=ds[a][i][j];
			else arr[a][b]=min(arr[a][b],ds[a][i][j]);
		    }
		}
	    }
	}
    }
    int ans=inf;
    for(int i=0;i<3;i++){
	int num=0;
	for(int j=0;j<3;j++){
	    if(i==j) continue;
	    if(arr[i][j]==-1) goto Hell;
	    num+=arr[i][j];
	}
	ans=min(ans,num);
    Hell:;
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(s[i][j]=='.' && ds[0][i][j]!=-1 && ds[1][i][j]!=-1 && ds[2][i][j]!=-1){
		ans=min(ans,ds[0][i][j]+ds[1][i][j]+ds[2][i][j]);
	    }
	}
    }
    if(ans==inf) ans=1;
    return cout<<ans-2<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
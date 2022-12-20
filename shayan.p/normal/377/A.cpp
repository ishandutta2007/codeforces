// Phoenix

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

const int maxn=510;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool mark[maxn][maxn];
string s[maxn];

int n,m,k;

void dfs(int x,int y){
    mark[x][y]=1;
    for(int i=0;i<4;i++){
	int X=x+dx[i],Y=y+dy[i];
	if(X>=0 && Y>=0 && X<n && Y<m && !mark[X][Y] && s[X][Y]=='.')
	    dfs(X,Y);
    }
    if(k>0){
	s[x][y]='X';
	--k;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(s[i][j]=='.'){
		dfs(i,j);
		goto Hell;
	    }
	}
    }
 Hell:;
    for(int i=0;i<n;i++){
	cout<<s[i]<<"\n";
    }
    return 0;
}
// Can U hack it?

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

const int maxn=2010,inf=2e9;

char s[maxn][maxn];
int ds[maxn][maxn];

bool mark[maxn][maxn];

deque<pii>d;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
    int n,m;scanf("%d%d",&n,&m);
    int r,c;scanf("%d%d",&r,&c);
    int x,y;scanf("%d%d",&x,&y);
    r--;c--;
    for(int i=0;i<n;i++)
	scanf("%s",&s[i]);
    for(int i=0;i<maxn;i++)
	for(int j=0;j<maxn;j++)
	    ds[i][j]=inf;
    ds[r][c]=0;
    d.push_back({r,c});

    while(!d.empty()){
	pii p=d.front();
	d.pop_front();
	if(mark[p.F][p.S])continue;
	mark[p.F][p.S]=1;
	for(int i=3;i>=0;i--){
	    int X=p.F+dx[i],Y=p.S+dy[i];
	    if(X>=0 && Y>=0 && X<n && Y<m && s[X][Y]=='.' && (ds[p.F][p.S]+(i==0))<ds[X][Y]){
		ds[X][Y]=ds[p.F][p.S]+(i==0);
		if(i==0)
		    d.push_back({X,Y});
		else
		    d.push_front({X,Y});
	    }
	}
    }
    int ans=0;
    for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	    ans+=(ds[i][j]<=y && (-j+c+ds[i][j])<=x);
    printf("%d\n",ans);
    return 0;
}
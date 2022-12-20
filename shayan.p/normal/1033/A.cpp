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

const int maxn=1010,mod=1e9+7;
const ll inf=1e18;

int cl,vr,n;
bool mark[maxn][maxn];

void dfs(int a,int b){
    mark[a][b]=1;
    for(int x=a-1;x<=a+1;x++){
	for(int y=b-1;y<=b+1;y++){
	    if(x>0 && x<=n && y>0 && y<=n && !mark[x][y] && (x-y)!=(vr-cl) && (x+y)!=(vr+cl) && x!=vr && y!=cl)
		dfs(x,y);
	}
    }
}

int main(){
    int ax,cx,ay,cy;
    scanf("%d%d%d%d%d%d%d",&n,&vr,&cl,&ax,&ay,&cx,&cy);
    dfs(ax,ay);
    if(mark[cx][cy])
	printf("YES\n");
    else
	printf("NO\n");
}
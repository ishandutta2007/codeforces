#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN][MAXN],b[MAXN][MAXN];
vector<P> ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m-1;j++)
            if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
            {
                b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
                ans.push_back(P(i,j));
            }
    bool f=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]!=b[i][j]) f=false;
    if(!f) puts("-1");
    else
    {
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
}
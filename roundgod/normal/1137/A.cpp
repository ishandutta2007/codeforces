#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN];
vector<int> row[MAXN];
vector<int> col[MAXN];
int ans[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            row[i].push_back(a[i][j]);
            col[j].push_back(a[i][j]);
        }
    for(int i=1;i<=n;i++)
    {
        sort(row[i].begin(),row[i].end());
        row[i].erase(unique(row[i].begin(),row[i].end()),row[i].end());
    }
    for(int i=1;i<=m;i++)
    {
        sort(col[i].begin(),col[i].end());
        col[i].erase(unique(col[i].begin(),col[i].end()),col[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int l1=lower_bound(row[i].begin(),row[i].end(),a[i][j])-row[i].begin();
            int l2=lower_bound(col[j].begin(),col[j].end(),a[i][j])-col[j].begin();
            int r1=row[i].end()-upper_bound(row[i].begin(),row[i].end(),a[i][j]);
            int r2=col[j].end()-upper_bound(col[j].begin(),col[j].end(),a[i][j]);
            printf("%d ",max(l1,l2)+1+max(r1,r2));
        }
        puts("");
    }
    return 0;
}
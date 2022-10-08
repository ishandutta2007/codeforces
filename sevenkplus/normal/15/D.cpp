#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 1010
int a[N][N],dr[N][N],dl[N][N],ur[N][N],ul[N][N];
ll s[N][N];
bool v[N][N],rx[N],ry[N];
typedef pair<pair<int,int>,ll> PI3;
vector<PI3>A,B;
inline bool cmp(const PI3 &a,const PI3 &b)
{
    if(a.second!=b.second)
        return a.second<b.second;
    if(a.first.first!=b.first.first)
        return a.first.first<b.first.first;
    if(a.first.second!=b.first.second)
        return a.first.second<b.first.second;
    return 0;
}
int main()
{   
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
        }
    for(int i=0;i<n;i++)
        rx[i]=i%x==0;
    for(int j=0;j<m;j++)
        ry[j]=j%y==0;
    rx[n]=ry[m]=1;
    for(int i=n;i>0;i--)
        for(int j=m;j>0;j--)
        {
            dr[i][j]=a[i][j];
            if(!rx[i]&&dr[i+1][j]<dr[i][j])
                dr[i][j]=dr[i+1][j];
            if(!ry[j]&&dr[i][j+1]<dr[i][j])
                dr[i][j]=dr[i][j+1];
        }
    for(int i=1;i<=n;i++)
        for(int j=m;j>0;j--)
        {
            ur[i][j]=a[i][j];
            if(!rx[i-1]&&ur[i-1][j]<ur[i][j])
                ur[i][j]=ur[i-1][j];
            if(!ry[j]&&ur[i][j+1]<ur[i][j])
                ur[i][j]=ur[i][j+1];
        }
    for(int i=n;i>0;i--)
        for(int j=1;j<=m;j++)
        {
            dl[i][j]=a[i][j];
            if(!rx[i]&&dl[i+1][j]<dl[i][j])
                dl[i][j]=dl[i+1][j];
            if(!ry[j-1]&&dl[i][j-1]<dl[i][j])
                dl[i][j]=dl[i][j-1];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ul[i][j]=a[i][j];
            if(!rx[i-1]&&ul[i-1][j]<ul[i][j])
                ul[i][j]=ul[i-1][j];
            if(!ry[j-1]&&ul[i][j-1]<ul[i][j])
                ul[i][j]=ul[i][j-1];
        }
    B.clear();
    for(int i=1;i<=n-x+1;i++)
        for(int j=1;j<=m-y+1;j++)
            B.push_back(make_pair(make_pair(i,j),s[i+x-1][j+y-1]-s[i-1][j+y-1]-s[i+x-1][j-1]+s[i-1][j-1]-(ll)min(min(dr[i][j],ul[i+x-1][j+y-1]),min(ur[i+x-1][j],dl[i][j+y-1]))*x*y));
    sort(B.begin(),B.end(),cmp);
    A.clear();
    for(vector<PI3>::iterator I=B.begin();I!=B.end();I++)
        if(!v[I->first.first][I->first.second])
        {
            A.push_back(*I);
            for(int i=I->first.first-x+1;i<I->first.first+x;i++)
                for(int j=I->first.second-y+1;j<I->first.second+y;j++)
                    if(i>0&&i<=n&&j>0&&j<=m)
                        v[i][j]=1;
        }
    printf("%d\n",A.size());
    for(vector<PI3>::iterator I=A.begin();I!=A.end();I++)
        printf("%d %d %I64d\n",I->first.first,I->first.second,I->second);
    return 0;
}
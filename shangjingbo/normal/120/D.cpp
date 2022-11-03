#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 105

int n,m,a[maxn][maxn],tar[10],now[10];
int l[10],r[10];

inline bool eq(int a[],int b[])
{
    for (int i=0;i<3;++i)
    if (a[i]!=b[i]) return false;
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            scanf("%d",&a[i][j]);
    for (int i=0;i<3;++i)
        scanf("%d",&tar[i]);
    sort(tar,tar+3);
    int cnt=0;
    for (int i=1;i<n;++i)
        for (int j=i+1;j<n;++j){
        //0..i-1, i..j-1, j..n-1
            memset(now,0,sizeof(now));
            l[0]=0;l[1]=i;l[2]=j;
            r[0]=i;r[1]=j;r[2]=n;
            for (int id=0;id<3;++id){
                for (int x=l[id];x<r[id];++x)
                    for (int y=0;y<m;++y)
                        now[id]+=a[x][y];
            }
            sort(now,now+3);
            if (eq(tar,now)) ++cnt;
        }
    
    for (int i=1;i<m;++i)
        for (int j=i+1;j<m;++j){
        //0..i-1, i..j-1, j..m-1
            memset(now,0,sizeof(now));
            l[0]=0;l[1]=i;l[2]=j;
            r[0]=i;r[1]=j;r[2]=m;
            for (int id=0;id<3;++id){
                for (int y=l[id];y<r[id];++y)
                    for (int x=0;x<n;++x)
                        now[id]+=a[x][y];
            }
            sort(now,now+3);
            if (eq(tar,now)) ++cnt;
        }
    
    
    printf("%d\n",cnt);
    
    return 0;
}
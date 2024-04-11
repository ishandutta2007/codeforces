#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

pair<int,int> f[12000],tk;
int n,s,o,ans;
int c[1000],a[100][100],b[100][100],ans1[10000],ans2[10000],ans3[10000],ans4[10000],hash[100][100];

int main()
{
    scanf("%d",&n);
    s=0;
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    for (int i=1;i<=n;i++) s+=c[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=c[i];j++)
        {
            scanf("%d",&a[i][j]);
            f[a[i][j]]=make_pair(i,j);
        }
    o=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=c[i];j++)
        {
            ++o;
            b[i][j]=o;
        }
    ans=0;
    memset(hash,0,sizeof(hash));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=c[i];j++)
            if (hash[i][j]==0)
            {
                hash[i][j]=1;
                tk=f[b[i][j]];
                while (hash[tk.first][tk.second]==0)
                {
                    hash[tk.first][tk.second]=1;
                    ++ans;
                    if (tk==f[b[i][j]]) {ans1[ans]=i;ans2[ans]=j;} else {ans1[ans]=ans3[ans-1];ans2[ans]=ans4[ans-1];}
                    ans3[ans]=tk.first;ans4[ans]=tk.second;
                    tk=f[b[tk.first][tk.second]];
                }
            }
    printf("%d\n",ans);
    for (int i=1;i<=ans;i++) printf("%d %d %d %d\n",ans1[i],ans2[i],ans3[i],ans4[i]);

    return 0;
}
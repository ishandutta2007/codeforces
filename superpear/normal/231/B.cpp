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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

int n,d,l,ans1,ans2,a[1000],flag[1000];
int main()
{
    cin>>n>>d>>l;
    for (int i=1;i<=n;i++) if (i%2==1) flag[i]=1; else flag[i]=-1;
    ans1=0;
    for (int i=1;i<=n;i++) if (flag[i]==1) ans1+=1; else ans1-=l;
    if (ans1>d) {cout<<-1<<endl;return 0;}
    ans2=0;
    for (int i=1;i<=n;i++) if (flag[i]==1) ans2+=l; else ans2-=1;
    if (ans2<d) {cout<<-1<<endl;return 0;}
    for (int i=1;i<=n;i++) if (flag[i]==1) a[i]=1; else a[i]=l;
    for (int i=ans1;i<d;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if ((flag[j]==1)&&(a[j]<l))
            {
                ++a[j];break;
            }
            if ((flag[j]==-1)&&(a[j]>1))
            {
                --a[j];break;
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    return 0;
}
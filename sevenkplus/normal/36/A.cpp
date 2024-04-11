#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1000];char s[1000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)if(s[i]=='1')a[m++]=i;
    for(int i=2;i<m;i++)
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){puts("NO");return 0;}
    puts("YES");
    return 0;
}
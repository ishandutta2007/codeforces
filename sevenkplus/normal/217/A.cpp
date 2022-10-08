#include<cstdio>
#include<algorithm>
using namespace std;
#define N 110
int f[N],px[N],py[N],n;bool v[N];
int fa(int x){return f[x]==x?x:(f[x]=fa(f[x]));}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",px+i,py+i);
    for(int i=0;i<n;i++)f[i]=i;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(px[i]==px[j]||py[i]==py[j])f[fa(i)]=fa(j);
    int S=0;
    for(int i=0;i<n;i++)
        if(!v[fa(i)])v[fa(i)]=1,S++;
    printf("%d\n",S-1);
    return 0;
}
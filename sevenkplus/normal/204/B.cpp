#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define INF 1000000007
#define N 100010
int n,a[N],b[N],p[N*2],L,S=INF;
map<int,int> A,B;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",a+i,b+i);
        if(a[i]==b[i]){A[a[i]]++,p[L++]=a[i];continue;}
        A[a[i]]++,B[b[i]]++,p[L++]=a[i],p[L++]=b[i];
    }
    sort(p,p+L),L=unique(p,p+L)-p;
    for(int i=0;i<L;i++)
    {
        int pa=A[p[i]],pb=B[p[i]];
        if((pa+pb)*2>=n)
            if(pa*2>=n)S=min(S,0);
            else S=min(S,(n+1)/2-pa);
    }
    if(S==INF)puts("-1");else printf("%d\n",S);
    return 0;
}
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define N 100010
vector<int> A[N],B[N];int n,m,f[N],S=0,d[N];bool v[N];
void ff(int x)
{
    v[x]=1;
    for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
        if(!v[*i])f[*i]=f[x]+1,ff(*i);else S=__gcd(S,abs(f[*i]-f[x]-1));
    for(vector<int>::iterator i=B[x].begin();i!=B[x].end();i++)
        if(!v[*i])f[*i]=f[x]-1,ff(*i);else S=__gcd(S,abs(f[*i]-f[x]+1));
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++)
        scanf("%d%d",&x,&y),A[x].pb(y),B[y].pb(x);
    for(int i=1;i<=n;i++)if(!v[i])ff(i);
    if(!S)S=n;printf("%d\n",S);
    return 0;
}
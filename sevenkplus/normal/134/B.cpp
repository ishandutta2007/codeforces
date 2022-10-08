#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000007
int ff(int x,int y)
{
    if(y%x==0)if(x==1)return y-1;else return INF;
    return ff(y%x,x)+y/x;
}
int main()
{
    int n;scanf("%d",&n);int S=INF;
    for(int i=1;i<=n;i++)S=min(S,ff(i,n));
    printf("%d\n",S);
    return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int g(int a,int b){return b?g(b,a%b):a;}
int main()
{
    int a,b,x,y;
    scanf("%d%d%d%d",&a,&b,&x,&y);
    int f=g(x,y);
    x/=f,y/=f;
    int k=min(a/x,b/y);
    printf("%d %d\n",k*x,k*y);
    return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int gett(int a,int b,int c)
{
    if(a%b<=c)a+=c-a%b;
    else a+=b+c-a%b;
    return a;
}
int main()
{
    scanf("%d%d",&n,&m);m=(m-1)*2;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==y){printf("%d\n",z);continue;}
        --x,--y;
        z=min(gett(z,m,x),gett(z,m,(m-x)%m));
        z=min(gett(z,m,y),gett(z,m,(m-y)%m));
        printf("%d\n",z);
    }
    return 0;
}
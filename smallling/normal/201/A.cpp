#include<cstdio>
#include<cmath>

using namespace std;

int x,ans;

int main()
{
    scanf("%d",&x);
    if(x==3)return puts("5"),0;
    for(ans=1;(ans*ans+1)/2<x;ans+=2);
    printf("%d",ans);
}
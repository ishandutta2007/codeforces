#include<cstdio>

using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n&1)printf("%d %d",9,n-9);
    else printf("%d %d",4,n-4);
}
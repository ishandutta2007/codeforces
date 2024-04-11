#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int _;scanf("%d",&_);
    while(_--)
    {
        int n;scanf("%d",&n);
        if(n&1)puts("0");else puts("1");
    }
    return 0;
}
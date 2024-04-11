#include <bits/stdc++.h>
using namespace std;
int n,t,x;
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&x);
        for (x=1;x<=n;x++) printf("%c",x%3+'a');puts("");
    }
}
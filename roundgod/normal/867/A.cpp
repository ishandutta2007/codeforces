#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int x,y,n;
char str[MAXN];
int main()
{
    x=0,y=0;
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=1;i<n;i++)
    {
        if(str[i]=='S'&&str[i-1]=='F') y++;
        if(str[i]=='F'&&str[i-1]=='S') x++;
    }
    if(x>y) printf("YES\n"); else printf("NO\n");
    return 0;
}
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    int cnt=0;
    a=a*10;
    while(true)
    {
        cnt++;
        if(cnt==1e5)
        {
            printf("-1\n");
            return 0;
        }
        if(a/b==c)
        {
            printf("%d\n",cnt);
            return 0;
        }
        a=(a%b)*10;
    }
    return 0;
}
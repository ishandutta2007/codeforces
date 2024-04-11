#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
char str[2];
int n;
char a[MAXN][2];
int main()
{
    scanf("%s",str);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    bool f=false,f1=false,f2=false;
    for(int i=0;i<n;i++)
    {
        if(a[i][0]==str[0]&&a[i][1]==str[1])
        {
            printf("YES\n");
            f=true;
            break;
        }
        if(a[i][0]==str[1]) f1=true;
        if(a[i][1]==str[0]) f2=true;
        if(f1&&f2)
        {
            printf("YES\n");
            f=true;
            break;
        }
    }
    if(!f) printf("NO\n");
    return 0;
}
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
char str[100];
int main()
{
    scanf("%s",str);
    int x=strlen(str);
    int cnt=0;
    for(int i=x-1;i>=0;i--)
    {
        if(str[i]=='1')
        {
            if(cnt>=6)
            {
                printf("yes\n");
                return 0;
            }
        }
        else cnt++;
    }
    printf("no\n");
    return 0;
}
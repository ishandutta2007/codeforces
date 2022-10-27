#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;

char s[200000 + 2];
int num[200000 + 2];
int sum[200000 + 2];
int main()
{
    int n,i,x,len;
    scanf("%s",s + 1);
    cin>>n;
    len = strlen(s + 1);
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        num[x] = !num[x];
    }
    for(i = 1; i <= len / 2; i++)
    {
        sum[i] = sum[i - 1] + num[i];
    }
    for(i = 1; i <= len; i++)
    {
        if(i <= len / 2)
        {
            if(sum[i] % 2 == 0) {
                printf("%c",s[i]);
            } else {
                printf("%c",s[len - i + 1]);
            }
        } else {
            if(sum[len - i + 1] % 2 == 0) {
                printf("%c",s[i]);
            } else {
                printf("%c",s[len - i + 1]);
            }
        }
    }
    return 0;
}
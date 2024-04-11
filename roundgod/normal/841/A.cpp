#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,m;
char str[MAXN];
int a[26];
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",str);
    int x=strlen(str);
    for(int i=0;i<x;i++)
        a[str[i]-'a']++;
    for(int i=0;i<26;i++)
        if(a[i]>m)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}
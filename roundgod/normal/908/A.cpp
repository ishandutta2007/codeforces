#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
char str[MAXN];
int main()
{
    scanf("%s",str);
    n=strlen(str);
    int cnt=0;
    for(int i=0;i<n;i++)
        if(str[i]=='1'||str[i]=='3'||str[i]=='5'||str[i]=='7'||str[i]=='9'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u') cnt++;
    printf("%d\n",cnt);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int n;
long long solve(char x)
{
    int decode;
    if (x>='0' && x<='9')
        decode=x-'0';
    else if (x>='A' && x<='Z')
        decode=10+x-'A';
    else if (x>='a' && x<='z')
        decode=36+x-'a';
    else if (x=='_')
        decode=63;
    else decode=62;
    long long ret=0;
    for (int i=0;i<=63;i++)
        for (int j=0;j<=63;j++)
            if((i&j)==decode)
                ret++;
    return ret;
}
int main()
{
    scanf("%s",s);
    n=strlen(s);
    long long ans=1;
    for (int i=0;i<n;i++)
        ans*=solve(s[i]),ans%=1000000007;
    cout<<ans<<endl;
}
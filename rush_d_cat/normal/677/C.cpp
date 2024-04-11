#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string.h>
using namespace std;
typedef __int64 ll;
char a[1000000+10];
const ll mod = 1000000007;
int f(char a)
{
    int t = (int)a;
    if(t<='9'&&t>='0') return t-'0';
    if(t>='a'&&t<='z') return 36+t-'a';
    if(t>='A'&&t<='Z') return 10+t-'A';
    if(a=='-') return 62;
    return 63;
}
int get(char a)
{
    int k=f(a);
    int res=0;
    for(int i=1;i<=6;i++)
    {
        if(k%2==0) res++;
        k/=2;
    }
    int ans=1;
    for(int i=1;i<=res;i++) ans*=3;
    return ans;
}
int main()
{
    scanf("%s",a);
    ll ans=1;
    for(int i=0;i<strlen(a);i++)
    {
        ans*=(ll)get(a[i]);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
int read(){int x=0,f=1;char c=getchar();while (c<'0' || c>'9') {if (c=='-') f=-1;c=getchar();}while (c>='0' && c<='9') x=x*10+c-'0',c=getchar();return x*f;}
const int N=1e6+5;
int a,b,c;
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
        rd(a);rd(b);rd(c);
        if (a==0 && c==0 && b%2==1) puts("2");else
        if (a==0 && b==0 && c%2==1) puts("3");else
        if (b==0 && c==0 && a%2==1) puts("1");else
        if ((a+2*b+3*c)%2==0) puts("0");else 
        puts("1");

    }

}
/*

*/
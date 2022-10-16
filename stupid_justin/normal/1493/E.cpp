#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define endl "\n"
using namespace std;
const int N=6e5+5;
const int M=605;
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n;
string l,r;
int main()
{
    cin>>n>>l>>r;
    if (l[0]!=r[0]){for (int i=0;i<n;i++) r[i]='1';}
    else
    {
        int i=0;
        for (;i<n;i++) if (r[i]=='1' && l[i]=='0') break;
        for (int j=i+1;j<n;j++) if (r[j]=='1' || l[j]=='0') r[n-1]='1';
    }
    cout<<r<<endl;
}
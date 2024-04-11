#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=1e5+5;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int a[N];
int b[N];
int n;
signed main()
{
    int T;
    rd(T);
    while (T--)
    {
        rd(n);
        for (int i=1;i<=n;i++) rd(a[i]);
        for (int i=1,j=n;i<j;i++,j--)
        {
            b[i]=-a[j];
            b[j]=a[i];
        }
        for (int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<"\n";
    }
}
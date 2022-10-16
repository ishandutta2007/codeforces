
#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2005+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}

int n,m,k;
char ch[N][N];
char bb[N][N];
void print()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) cout<<bb[i][j];
        cout<<endl;
    }
}
bool get(string s)
{
    int cnt=0,cnt1=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (ch[i][j]!='.' && s[(i+j)%3]!='.') bb[i][j]=s[(i+j)%3]; else bb[i][j]=ch[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (ch[i][j]!='.') cnt+=(ch[i][j]!=bb[i][j]),cnt1++;
    return cnt<=cnt1/3;
}
signed main()
{
    int T;
    cin>>T;
    while (T--)
    {
        rd(n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) cin>>ch[i][j];
        int cnt=0;
        if (get(".XO")) print();
        else if (get("OX.")) print();
        else if (get("XO.")) print();
        else if (get("O.X")) print();
        else if (get("X.O")) print();
        else if (get(".OX")) print();
    }
}
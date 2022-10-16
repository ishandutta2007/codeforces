#include<bits/stdc++.h>
#define rd(x) x=read()
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=2e5+5;
int num[N];
int m,n,c,x;
signed main()
{
    cin>>n>>m>>c;
    while (m--)
    {
        cin>>x;
        if (x<=c/2)
        {
            for (int i=1;i<=n;i++) 
            if ((num[i]>x) || num[i]==0)
            {
                num[i]=x;
                cout<<i<<endl;
                break;
            }
        } else
        {
            for (int i=n;i>=1;i--) 
            if ((num[i]<x) || num[i]==0)
            {
                num[i]=x;
                cout<<i<<endl;
                break;
            }
        }
        fflush(stdout);
    }       
}
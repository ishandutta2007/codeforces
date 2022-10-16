
#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=3e5+5;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,l,r,sum;
int L,R,SUM;
int a[N+1],w[N+1];
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++) rd(a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) w[a[i]]++;
    l=r=a[1];sum=w[l];
    for (int i=a[1]+1;i<N;i++)
    {
        //112
        if (w[i])
        {
            if (i==r+1) 
            {
                r++;
                sum+=w[r];
                if (w[r]==1) 
                {
                    if (sum>SUM) 
                    {
                        L=l,R=r,SUM=sum;
                    }
                    l=r,sum=w[r];
                }
            }
            else
            {
                if (sum>SUM) 
                {
                    L=l,R=r,SUM=sum;
                }
                l=r=i,sum=w[i];
            }
        }
    }
    if (sum>SUM) 
                {
                    L=l,R=r,SUM=sum;
                }
    cout<<SUM<<endl;
    for (int i=L;i<=R;i++) cout<<i<<" ",w[i]--;
    for (int i=R;i>=L;i--) 
        for (int j=1;j<=w[i];j++) cout<<i<<" ";
    cout<<endl;
}
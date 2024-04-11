# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
using namespace std;
long long po[60];
long long a[100000];
bool vis[1000];
int main()
{
    po[0]=1;
    for (long long i=1;i<=60;i++)
        po[i]=po[i-1]*2;
    long long n,m;
    cin>>n>>m;
    long long nowpo=n-2;
    for (long long i=0;i<n;i++)
    {
        long long now=nowpo;
        int j;
        if (i>0)
        j=a[i-1];
        else
            j=0;
        if (j>n)
            j=n-1;
        int ch=1;
        while(true)
        {
            j+=ch;
            if (j==n+1)
                j=n-1,ch*=-1;
            if (j==0)
                j=1,ch*=-1;
            if (vis[j])
                continue;
            if (po[nowpo]>=m)
            {
                a[i]=j;
                vis[j]=1;
                nowpo--;
                nowpo=max(nowpo,(long long)0);
                break;
            }
            else
                m-=po[nowpo];
            nowpo--;
            nowpo=max(nowpo,(long long)0);
        }
    }
    for (long long i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
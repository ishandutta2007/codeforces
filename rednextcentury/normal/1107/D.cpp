#include <bits/stdc++.h>
using namespace std;
int a[5201][5201];
void fillHexa(char x,int i,int tot)
{
    int num;
    if (x>='A' && x<='Z')
        num=10+x-'A';
    else num=x-'0';
    int cur=3;
    for (int j=0;j<4;j++)
    {
        a[i][tot+cur]=num%2;
        cur--;
        num/=2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int tot=1;
        for (int j=1;j<=n/4;j++)
        {
            char x;
            cin>>x;
            fillHexa(x,i,tot);
            tot+=4;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for (int i=n;i>=2;i--)
    {
        if (n%i)continue;
        bool ok=1;
        for (int j=i;j<=n;j+=i)
        {
            for (int k=i;k<=n;k+=i)
            {
                int x = a[j][k]-a[j-i][k]-a[j][k-i]+a[j-i][k-i];
                if (x!=0 && x!=i*i)ok=0;
                if (!ok)break;
            }
            if(!ok)break;
        }
        if (ok){cout<<i<<endl;return 0;}
    }

    cout<<1<<endl;
}
#include<bits/stdc++.h>
using namespace std;
bool is[1001][1001];
int po[1001][1001][2];
int GCD(int a,int b)
{
    if (a==0)return b;
    if (b==0)return a;
    if (a%b==0)return b;
    if (b%a==0)return a;
    return GCD(b%a,a);
}
int p[5000000];
int main()
{
    int a,b;
    cin>>a>>b;
    for (int i=0;i<=2000;i++)
        p[i*i]=i;

    for (int i=1;i<=1000;i++)
    {
        for (int j=1;j<=1000;j++)
        {
            if (i+j==0)continue;
            if (p[i*i+j*j]==a)
            {
                    is[i/GCD(i,j)][j/GCD(i,j)]=1;
                    po[i/GCD(i,j)][j/GCD(i,j)][0]=j;
                    po[i/GCD(i,j)][j/GCD(i,j)][1]=i;
            }
        }
    }
    for (int i=1;i<=1000;i++)
    {
        for (int j=-1;j>=-1000;j--)
        {
            if (i==j && i==0)continue;
            if (p[i*i+j*j]==b)
            {
                int u=i/GCD(i,-j);
                int v=-j/GCD(i,-j);
                if (is[v][u] && (i!=po[v][u][1]))
                {
                    cout<<"YES"<<endl;
                    cout<<0<<' '<<0<<endl;
                    cout<<po[v][u][0]<<' '<<po[v][u][1]<<endl;
                    cout<<j<<' '<<i<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
#include<bits/stdc++.h>

using namespace std;
int a[101][101];
int has[1001][100];
void calc(int i,int j)
{
    int h=a[i][j];
    int cur=0;
    while(h)
    {
        has[i][cur]=max(has[i][cur],h%2);
        has[j][cur]=max(has[j][cur],h%2);
        h/=2;
        cur++;
    }
}
long long p[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p[0]=1;
    for (int i=1;i<40;i++)
        p[i]=p[i-1]*2;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if (i!=j)
            {
                calc(i,j);
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        int cur=0;
        for (int j=0;j<40;j++)
        {
            if (has[i][j])
                cur+=p[j];
        }
        cout<<cur<<" ";
    }
    cout<<endl;
}
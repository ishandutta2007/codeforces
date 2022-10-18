#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 2000 + 11;

bool dp[N][52][22];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    int m;
    cin>>m;
    int p=30;
    dp[0][0+p][0]=1;
    for (int i=1; i<=m; i++)
    for (int j=-20; j<=20; j++)
    for (int t=0; t<=10; t++)
    for (int d=1; d<=10; d++)
    if (s[d]=='1'&&dp[i-1][j+p][t]&&t!=d)
    {
        if (i%2==1&&j+d>0) dp[i][j+d+p][d]=1;
        if (i%2==0&&j-d<0) dp[i][j-d+p][d]=1;
    }
    for (int j=-20; j<=20; j++)
    for (int xx=1; xx<=10; xx++)
        if (dp[m][j+p][xx])
    {
        vector<int> v;
        int x=j;
        int dd=0;
        for (int i=m; i>=1; i--)
        for (int xx=1; xx<=10; xx++)
            if (dp[i][x+p][xx]&&dd!=xx)
        {
            v.pb(xx);
            if (i%2==1) x-=xx; else x+=xx;
            dd=xx;
            break;
        }
        cout<<"YES"<<endl;
        for (int i=v.size()-1; i>=0; i--)
            cout<<v[i]<<" ";
        cout<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}
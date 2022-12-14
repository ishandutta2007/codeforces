#include<bits/stdc++.h>
using namespace std;
int best[11][11][11];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int x=0;x<=10;x++)
    for (int y=0;y<=10;y++)
    for (int i=0;i<=10;i++)
        best[x][y][i]=1e9;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            for (int x=0;x<=100;x++)
            {
                for (int y=0;y<=100;y++)
                {
                    if (x+y==0)continue;
                    int sum = x*i+y*j;
                    best[i][j][sum%10]=min(best[i][j][sum%10],x+y-1);
                }
            }
        }
    }
    string s;
    cin>>s;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            long long ret=0;
            for (int x=0;x+1<s.size();x++)
            {
                int dif = ((int)(s[x+1]-'0')) - ((int)(s[x]-'0'));
                if (dif<0)dif+=10;
                ret+=best[i][j][dif];
            }
            if (ret>=1e9)ret=-1;
            cout<<ret<<' ';
        }
        cout<<endl;
    }
}
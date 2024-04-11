#include <bits/stdc++.h>
using namespace std;
int costX[1000002];
int costY[1000002];
string s[1000002];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=0;i<n;i++)
            cin>>s[i];
        for (int i=0;i<n;i++)costX[i]=0;
        for (int i=0;i<m;i++)costY[i]=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (s[i][j]=='.')
                    costX[i]++,costY[j]++;
        int ret=1e9;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                    ret=min(ret,costX[i]+costY[j]-(s[i][j]=='.'));
        cout<<ret<<endl;
    }


}
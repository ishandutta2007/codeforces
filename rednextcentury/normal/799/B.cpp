#include<bits/stdc++.h>
using namespace std;
multiset<int> S[5][5];
int a[1000000],b[1000000],p[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>p[i];
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>b[i];
    for (int i=0;i<n;i++)
        S[a[i]][b[i]].insert(p[i]);
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        int mn=1000000004;
        int s,t;
        for (int i=1;i<=3;i++)
        {
            for (int j=1;j<=3;j++)
            {
                if ((i==x || j==x) && S[i][j].size())
                {
                    if (*S[i][j].begin() < mn)
                        mn=*S[i][j].begin(),s=i,t=j;
                }
            }
        }
        if (mn==1000000004)
            cout<<-1<<' ';
        else
        {
            cout<<mn<<' ';
            S[s][t].erase(S[s][t].begin());
        }
    }
    cout<<endl;
}
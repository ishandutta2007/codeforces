#include<bits/stdc++.h>
using namespace std;
int x[1000000];
int y[1000000];
int a[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for (int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for (int i=0;i<n;i++)
    {
        map<pair<int,int> ,int> mp;
        for (int j=1;j<n;j++)
            mp[{a[j],b[j]}]++;
        int Tx = x[i]+a[0], Ty = y[i]+b[0];
        bool ok=1;
        for (int j=0;j<n;j++)
        {
            if (i==j)continue;
            if (mp.find({Tx-x[j],Ty-y[j]})!=mp.end())
                mp[{Tx-x[j],Ty-y[j]}]--;
            else {
                ok=0;break;
            }
        }
        if (ok){cout<<Tx<<' '<<Ty<<endl;return 0;}
    }
}
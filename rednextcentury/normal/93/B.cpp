# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
using namespace std;
struct cup
{
    long double amount;
    int index;
};
cup cups[100][100];
int g[100];
int main()
{
    long double n,w,m;
    cin>>n>>w>>m;
    long double each=(n*w)/m;
    int cur=0;
    long double has=0;
        long double can=each-has;
    for (int i=0;i<n;i++)
    {
        if (can<0.000001)
            cur++,can=each;
        if (can+each<w-0.000001)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if (w<=can)
        {
            cups[cur][g[cur]].amount=w;
            cups[cur][g[cur]++].index=i+1;
            has+=w;
            can-=w;
        }
        else
        {
            if (can>0)
            {
            cups[cur][g[cur]].amount=can;
            cups[cur][g[cur]++].index=i+1;
            }
            cur++;
            cups[cur][g[cur]].amount=w-can;
            cups[cur][g[cur]++].index=i+1;
            has=w-(can);
            can=each-has;
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<m;i++)
    {
        for (int x=0;x<g[i];x++)
        {
            cout<<setprecision(7)<<fixed<<cups[i][x].index<<" "<<cups[i][x].amount<<" ";
        }
        cout<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int bef(int &i)
{
    i--;
    if (i==0)
        i=4;
}
int l[5][10],p[5];
int main()
{
    bool can=0;
    for (int i=1;i<=4;i++)
        cin>>l[i][0]>>l[i][1]>>l[i][2]>>p[i];
    for (int i=1;i<=4;i++)
    {
        if (p[i]==0)continue;
        if (l[i][0] || l[i][1] || l[i][2])can=1;
        int x=i;
        bef(x);
        if (l[x][2])can=1;
        bef(x);
        if (l[x][1])can=1;
        bef(x);
        if (l[x][0])can=1;
    }
    if (can)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
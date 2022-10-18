#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,s;
    cin>>m>>s;
    if (s==0)
    {
        if (m==1) return cout<<"0 0", 0;
        return cout<<"-1 -1", 0;
    }
    if (s>9*m) return cout<<"-1 -1", 0;
    int ss=s;
    for (int i=1; i<=m; i++)
    {
        int mn=0;
        if (i==1) mn=1;
        if (ss-mn>9*(m-i)) mn=ss-9*(m-i);
        cout<<mn;
        ss-=mn;
    }
    cout<<" ";
    ss=s;
    for (int i=1; i<=m; i++)
    {
        int mn=min(ss,9);
        cout<<mn;
        ss-=mn;
    }
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e6 + 11;

int x[N],y[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i=1; i<=3; i++)
        cin>>x[i]>>y[i];
    int res=2e9;
    int ii=0;
    int jj=0;
    for (int i=0; i<=1000; i++)
    for (int j=0; j<=1000; j++)
    {
        int ans=1;
        for (int p=1; p<=3; p++)
            ans+=abs(x[p]-i)+abs(y[p]-j);
        if (ans<res)
        {
            res=ans;
            ii=i;
            jj=j;
        }
    }
    cout<<res<<"\n";
    for (int p=1; p<=3; p++)
    {
        while (x[p]!=ii)
        {
            cout<<x[p]<<" "<<y[p]<<"\n";
            if (x[p]<ii) x[p]++; else x[p]--;
        }
        while (y[p]!=jj)
        {
            cout<<x[p]<<" "<<y[p]<<"\n";
            if (y[p]<jj) y[p]++; else y[p]--;
        }
    }
    cout<<ii<<" "<<jj<<endl;
}
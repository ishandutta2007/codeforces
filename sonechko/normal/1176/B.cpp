#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;


void up()
{
    int n;
    cin>>n;
    int ans=0,k1=0,k2=0,res=0;
    for (int i=1; i<=n; i++)
    {
        int p;
        cin>>p;
        if (p%3==0) ans++; else
        if (p%3==1) k1++; else k2++;
    }
    for (int p=0; p<=min(k1,k2); p++)
    {
        int pp=ans+p;
        int t1=(k1-p),t2=(k2-p);
        pp+=t1/3;
        pp+=t2/3;
        res=max(res,pp);
    }
    cout<<res<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int j=1; j<=t; j++)
        up();
}
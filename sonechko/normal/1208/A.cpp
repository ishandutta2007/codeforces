#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int a,b,n;
        cin>>a>>b>>n;
        if (n==0) {cout<<a<<"\n"; continue;}
        if (n==1) {cout<<b<<"\n"; continue;}
        int ans=0;
        for (int j=1,t=0; t<=30; t++,j*=2)
        {
            int c1=0,c2=0;
            if ((a&j)) c1=1;
            if ((b&j)) c2=1;
            if (c1==1&&c2==1&&n%3!=2) ans+=j; else
            if (c1==1&&c2==0&&n%3!=1) ans+=j; else
            if (c1==0&&c2==1&&n%3!=0) ans+=j;
        }
        cout<<ans<<"\n";
    }
}
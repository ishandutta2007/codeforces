#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 3e5 + 11;

int use[N],x[N],uses[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int ii=1; ii<=t; ii++)
    {
        int n,k;
        cin>>n>>k;
        for (int i=1; i<=n; i++)
            use[i]=0;
        for (int i=1; i<=k; i++)
        {
            int x;
            cin>>x;
            use[x]=1;
        }
        for (int p=1; p<=n*5; p++)
        {
            int dd=0;
            for (int i=1; i<=n; i++)
            if (use[i]==0) dd=1;
            if (dd==0) {cout<<p<<endl; break;}
            for (int i=1; i<=n; i++)
                uses[i]=0;
            for (int i=1; i<=n; i++)
                if (use[i+1]==1) uses[i]=1; else
                if (use[i-1]==1) uses[i]=1; else
                if (use[i]==1) uses[i]=1;
            for (int i=1; i<=n; i++)
                use[i]=uses[i];
        }
        for (int i=1; i<=n; i++)
        {
            use[i]=0;
            uses[i]=0;
        }
    }
}
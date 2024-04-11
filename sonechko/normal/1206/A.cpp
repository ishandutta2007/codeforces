#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int t1=0,t2=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        t1=max(t1,x);
    }
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        t2=max(t2,x);
    }
    cout<<t1<<" "<<t2;
}
/**
8
1 1 1 1 210 140 84 60
**/
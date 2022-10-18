#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (n==1) cout<<"-1\n"; else
        if (n%3==0||n%3==2)
        {
            for (int i=1; i<n; i++)
                cout<<2;
            cout<<3;
            cout<<"\n";
        } else
        {
            for (int i=1; i<n-1; i++)
                cout<<2;
            cout<<33;
            cout<<"\n";
        }
    }
}
/**
23
223
2223
**/
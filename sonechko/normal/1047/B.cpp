#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int p=0;
    for (int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        p=max(p,x+y);
    }
    cout<<p;
}
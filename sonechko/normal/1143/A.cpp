#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;

int a[N];

int main()
{
    int n;
    cin>>n;
    int m0=0,m1=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==0) m0=i; else m1=i;
    }
    cout<<min(m0,m1);
}
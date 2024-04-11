#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 2e5 + 11;

int a[N];

void up()
{
    int n;
    cin>>n;
    int t1=0,t2=0;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
        if (a[i]==a[i-1]+1) t1++; else
        if (a[i]==a[i-1]-1) t2++;
    if (a[1]==a[n]+1) t1++;
    if (a[1]==a[n]-1) t2++;
    if (t1==n-1||t2==n-1) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}
/**
1
4
0 0 -1 0
0 0 -1 0
0 0 0 0
1 1 1 1
**/
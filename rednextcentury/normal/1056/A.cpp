#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x;
            cin>>x;
            a[x]++;
        }
    }
    for (int i=1;i<=100;i++)
        if (a[i]==n)cout<<i<<' ';
}
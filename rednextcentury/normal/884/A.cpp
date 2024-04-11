#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mp make_pair
#define ll long long
int main()
{
    fast;
    int n,t;
    cin>>n>>t;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        t-=(86400-x);
        if (t<=0)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
}
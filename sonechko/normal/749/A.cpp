#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
int ans=0;
int main()
{
    sync;
    #ifdef LOCAL
    #else
    #endif
    int n;
    cin>>n;
    if (n%2==1)
    {
        n-=3;
        cout<<n/2+1<<endl;
        for (int i=1; i<=n/2; i++)
            cout<<2<<" ";
        cout<<3<<endl;
    } else
    {
        cout<<n/2<<endl;
        for (int i=1; i<=n/2; i++)
            cout<<2<<" ";
        cout<<endl;
    }
}
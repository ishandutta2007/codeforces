#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
int n;
int main()
{
    sync;
    int n;
    cin>>n;
    ll k=0;
    for (int i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        k+=l-1;
        cout<<3-(k%2+1)<<endl;
    }
}
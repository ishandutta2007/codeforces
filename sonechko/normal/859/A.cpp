#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int r=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        r=max(r,l);
    }
    cout<<max(0,r-25)<<endl;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=k; i++)
    {
        if (n%2==0) n/=2;
        if (n%5==0) n/=5;
    }
    cout<<n;
    for (int i=1; i<=k; i++)
        cout<<0;
}
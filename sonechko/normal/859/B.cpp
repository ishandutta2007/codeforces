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
    int ans=1000000000;
    for (int i=1; i<=10000000; i++)
    {
        int d=n/i;
        if (n%i!=0) d++;
        ans=min(ans,d*2+i*2);
    }
    cout<<ans<<endl;
}
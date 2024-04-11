#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int l=n*2;
    int r=n*5;
    int p=n*8;
    int ans=(l+k-1)/k+(r+k-1)/k+(p+k-1)/k;
    cout<<ans<<endl;
}
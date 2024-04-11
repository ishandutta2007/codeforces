#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 100 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    if (k<n)
    {
        cout<<k+1<<" "<<1<<endl;
        return 0;
    }
    k-=n-1;
    int g=(k+m-2)/(m-1);
    cout<<n-g+1<<" ";
    if (g%2==1)
    {
        if (k%(m-1)==0) cout<<m<<endl; else cout<<1+k%(m-1)<<endl;
    } else
    {
        if (k%(m-1)==0) cout<<2<<endl; else cout<<m-k%(m-1)+1<<endl;
    }
}
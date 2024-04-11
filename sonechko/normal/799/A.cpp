#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,t,k,d;
    cin>>n>>t>>k>>d;
    int pp=(n+k-1)/k*t;
    int ans=0;
    int ks1=0,ks2=0;
    for (int i=d+1; i<=10000000; i++)
    {
        int p=d/t*k;
        int f=(i-d/t*t)/t*k;
        int ff=(i-d)/t*k;
        if (p+f+ff>=n) {ans=i; break;}
    }
    if (ans<pp) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        long long ret=0;
        while(n!=0) {
            if (n%k==0)n/=k,ret++;
            else ret+=n%k,n-=n%k;
        }
        cout<<ret<<endl;
    }
}
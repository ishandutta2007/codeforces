#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;


int main()
{
    int n;
    cin>>n;
    if (n<=2) return cout<<"No", 0;
    cout<<"Yes\n";
    int c=n/2;
    if (n%2==1) c=(n+1)/2;
    cout<<1<<" "<<c<<endl;
    cout<<n-1<<" ";
    for (int i=1; i<=n; i++)
        if (i!=c) cout<<i<<" ";

}
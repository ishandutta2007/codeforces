# include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int mx=min(n-k,k*2);
    int mn=min(1,n-k);
    mn=min(mn,mx);
    cout<<mn<<' '<<mx<<endl;
}
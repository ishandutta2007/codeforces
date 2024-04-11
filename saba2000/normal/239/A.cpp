#include <iostream>
using namespace std;
int main()
{
    int x,y,n,k,r=0;
    cin>>y>>k>>n;
    for (int i=k; i<=n; i+=k)
    if (i%k==0 && i-y>0) {cout<<i-y<<" "; r=1;} 
    if (r==0)cout << -1;
    return 0;
    }
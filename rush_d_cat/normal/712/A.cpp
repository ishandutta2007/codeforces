#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef __int64 ll;
const ll M = 400000 + 100;
const ll inf  = 1e9 + 7;
ll a[M];
int main()
{
    int n,i;cin >> n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++)
    {
        if(i==n) cout<<a[i];
        else cout<<a[i]+a[i+1];
        if(i==n) cout<<endl;
        else cout<<" ";
    }
}
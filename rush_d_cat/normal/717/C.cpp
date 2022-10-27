#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include<queue>
using namespace std;
typedef __int64 ll;
typedef pair<int,int> P;
const ll M = 100000 + 100;
const ll inf  = 1e9 + 7;
int n;
ll a[M];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+1+n);
    ll res = 0;
    for(int i=1;i<=n;i++)
    {
        res+=a[i]*a[n+1-i];
        res%=10007;
    }
    cout<<res;
}
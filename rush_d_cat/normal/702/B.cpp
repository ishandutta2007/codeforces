#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 ll;
int a[100000+2];
map<int, int> mp;
int main()
{
    int n,i,j;
    ll res = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        res += mp[a[i]];
        for(j = 1; j <= 30; j++)
        {
            mp[(1<<j) - a[i]] ++;
        }
    }
    cout <<res<<endl;

    return 0;
}
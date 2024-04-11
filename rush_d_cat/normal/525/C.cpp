#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;
typedef __int64 ll;
const int maxn = 1000000 + 2;
ll len[maxn];
bool used[maxn];
int main()
{
    int n, i;
    memset(len, 0, sizeof(len));
    memset(used, 0, sizeof(used));
    ll len1 = 0, len2 = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> len[i];
    }
    sort(len + 1, len + 1 + n);
    if(n <= 3)
    {
        cout << 0 << endl;
        return 0;
    }
    ll res = 0;
    for(i = n; i >= 1; i--)
    {
        if(len1 > 0 && len2 > 0)
        {
            res += len1 * len2;
            len1 = 0; len2 = 0;
        }
            
        if(len[i] - len[i - 1] > 1 || used[i])
            continue;

        if(len[i] - len[i - 1] <= 1)
        {
            used[i - 1] = 1;
            if(len1 == 0) len1 = len[i - 1];
            else len2 = len[i - 1];
        }
    }
    cout << res <<endl;
}
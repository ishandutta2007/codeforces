#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define maxn 500000

typedef long long ll;

int n;
ll sum[maxn];
int a[maxn];
map< int, int > last;
ll res;
vector< int > del;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    res = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        last[a[i]] = i;
        if (res > a[i])
        {
            res = a[i];
        }
    }
    res *= 2;
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1];
        if (a[i] >= 0)
        {
            sum[i] += a[i];
        }
    }
    for (int i = n - 1; i >= 1; --i)
    {
        int cur = last[a[i]];
        assert(cur >= i);
        if (cur > i)
        {
            ll tmp = 2LL * a[i] + sum[cur - 1] - sum[i];
            if (res < tmp)
            {
                res = tmp;
            }
        }
    }
    for (int i = n - 1; i >= 1; --i)
    {
        int cur = last[a[i]];
        assert(cur >= i);
        if (cur > i && 2LL * a[i] + sum[cur - 1] - sum[i] == res)
        {
            del.clear();
            for (int j = 1; j < i; ++j)
            {
                del.push_back(j);
            }
            for (int j = i + 1; j < cur; ++j)
            {
                if (a[j] < 0)
                {
                    del.push_back(j);
                }
            }
            for (int j = cur + 1; j <= n; ++j)
            {
                del.push_back(j);
            }
            break;
        }
    }
    cout << res << " " << del.size() << "\n";
    for (vector < int >::iterator it = del.begin(); it != del.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}
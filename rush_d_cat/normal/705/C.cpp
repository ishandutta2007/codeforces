#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
typedef __int64 ll;
const int maxn = 300000 + 10;
vector<int> vec[maxn];
int bit[maxn];
int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= i & (-i);
    }
    return s;
}
void add(int i, int x)
{
    while(i <= maxn)
    {
        bit[i] += x;
        i += i & (-i);
    }
}
int main()
{
    int n, q, i, j, op, x ,max_t = 0;
    cin >> n >> q;
    int res = 0, cnt = 0;
    for(i = 1; i <= q; i++)
    {
        cin >> op >> x;
        if(op == 1)
        {
            res ++;
            vec[x].push_back(++cnt);
            add(cnt, 1);
            cout << res << endl;
        }
        if(op == 2)
        {
            int sz = vec[x].size();
            int tmp = 0;
            for(j = 0; j < sz; j++)
            {
                if(vec[x][j] > max_t) tmp ++;
                add(vec[x][j], -1);
            }
            vec[x].clear();
            res -= tmp;
            cout << res << endl;
        }
        if(op == 3)
        {
            res -= ((sum(x) - sum(max_t))<0) ? 0 : (sum(x) - sum(max_t));
            max_t = max(max_t, x);
            cout << res << endl;
        }
    }
    return 0;
}
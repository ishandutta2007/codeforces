#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 200000 + 10;
typedef long long ll;
int n, i, j;
int pre[MAXN], cnt[MAXN];
int main()
{
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for(i = 1; i < MAXN; i++) pre[i] = pre[i-1] + cnt[i];
    ll res = 0;
    for(i = 1; i < MAXN; i++)
    {
        ll tmp = 0;
        if(cnt[i] == 0) continue;
        for(j = i; j < MAXN; j += i)
        {
            int min_ = min(j+i-1, MAXN-1);
            tmp += (ll)(pre[min_] - pre[j-1]) * (ll)j;
        }
        res = max(res ,tmp);
    }
    cout << res << endl;
}
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10011;
pair <int, int> p[N];

int main()
{
    ios :: sync_with_stdio(false);
    int n, b, q;
    cin >> n >> b >> q;
    for(int i = 0; i < q; i ++)
        cin >> p[i].first >> p[i].second;
    p[q ++] = {b, n};
    sort(p, p + q);

    bool flag = true;
    for(int k = 1; k < (1 << 5); k ++)
    {
        int acc = 0;
        int last = 0;
        int lc = 0;
        for(int i = 0; i < q; i ++)
        {
            int now = p[i].first;
            int cnt = p[i].second - lc;
            if(now - last < cnt || cnt < 0)
                flag = false;
            int tmp = 0;
            for(int j = last + 1; j <= now; j ++)
                if((k >> (j % 5)) & 1)
                    tmp ++;
            acc += min(tmp, cnt);
            last = now;
            lc = p[i].second;
        }
        if(acc < __builtin_popcount(k) * n / 5)
            flag = false;
    }

    cout << (flag ? "fair" : "unfair") << '\n';
    return 0;
}
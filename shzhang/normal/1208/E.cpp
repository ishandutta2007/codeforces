#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

ll psum[1000005]; int n, w, len;

void add(int l, int r, ll val)
{
    if (val < 0) {
        if (len * 2 <= w) return;
        int a = len;
        int b = w-len+1;
        r = min(r, a);
        l = max(l, b);
    }
    if (l > r) return;
    /*if (l == r && (l - len >= 1 || l + len <= w))
        val = max(val, 0LL);*/
    psum[l] += val;
    psum[r+1] -= val;
}

int main()
{
    cin >> n >> w;
    for (int arr = 1; arr <= n; arr++) {
        cin >> len;
        vector<ll> vals;
        vals.push_back(0);
        for (int j = 1; j <= len; j++) {
            ll a;
            cin >> a;
            vals.push_back(a);
        }
        /*if (len == w) {
            for (int i = 1; i <= len; i++) {
                psum[i] += vals[i];
                psum[i+1] -= vals[i];
            }
            continue;
        }*/
        ll curmax = -2000000000LL;
        //printf("NEW\n");
        if (len * 2 <= w) {
            for (int i = 1; i <= len; i++) {
                curmax = max(curmax, vals[i]);
                add(i, i, curmax);
                //printf("workinga %d\n", i);
            }
            curmax = -2000000000LL;
            for (int i = w; i > w - len; i--) {
                //printf("workingb %d\n", i);
                curmax = max(curmax, vals[i - w + len]);
                add(i, i, curmax);
            }
            add(len+1, w-len, curmax);
        } else {
            deque<int> que;
            for (int i = 1; i <= w; i++) {
                while (!que.empty() && que.front() <= i - w + len - 1) que.pop_front();
                if (i <= len) {
                    while (!que.empty() && vals[que.back()] < vals[i]) que.pop_back();
                    que.push_back(i);
                }
                add(i, i, vals[que.front()]);
            }
        }
    }
    for (int i = 1; i <= w; i++) psum[i] += psum[i-1];
    for (int i = 1; i <= w; i++) cout << psum[i] << ' ';
    return 0;
}
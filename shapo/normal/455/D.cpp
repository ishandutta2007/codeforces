#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <cmath>

using namespace std;

const int MAXN = 100500;
const int MAXK = 500;

int lb[MAXK], rb[MAXK];
deque< int > chunk[MAXK];
int n, q, block;
int cnt[MAXK][MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector< int > a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    block = min(n, int(sqrt((n + 1) / 2)));
    for (int curP = 0, curId = 0; curP < n; curP += block, ++curId) {
        chunk[curId].clear();
        lb[curId] = curP, rb[curId] = min(n, lb[curId] + block);
        for (int j = lb[curId]; j < rb[curId]; ++j) {
            chunk[curId].push_back(a[j]);
        }
    }
    int allBl = (n + block - 1) / block;
    for (int i = 0; i < allBl; ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = 0;
        }
        for (const auto val : chunk[i]) {
            cnt[i][val]++;
        }
    }
    int lastans = 0;
    cin >> q;
#ifdef DEBUG
    cerr << "block = " << block << endl;
#endif
    for (int qn = 0; qn < q; ++qn) {
        int type, l, r, k;
        cin >> type >> l >> r;
        l = (l + lastans - 1) % n;
        r = (r + lastans - 1) % n;
        if (l > r) {
            swap(l, r);
        }
#ifdef DEBUG
        cerr << "l = " << l << " r = " << r << endl;
#endif
        if (type == 1) {
            int ind = -1;
            for (int i = 0; i < allBl; ++i) {
                if (lb[i] <= l && rb[i] - 1 >= r) {
                    ind = i;
                    break;
                }
            }
            if (ind != -1) {
                int pos = rb[ind];
                auto it = chunk[ind].end();
                while (pos != r) { --pos, --it; }
                int sVal = *it;
                chunk[ind].erase(it);
                it = chunk[ind].begin(), pos = lb[ind];
                while (pos != l) { ++pos, ++it; }
                chunk[ind].insert(it, sVal);
                continue;
            }
            int blockId = allBl - 1;
            while (lb[blockId] > r) {
                --blockId;
            }
            int tmpVal = 0;
            {
                int pos = lb[blockId];
                auto it = chunk[blockId].begin();
                while (pos != r) {
                    ++pos, ++it;
                }
                tmpVal = *it;
                --cnt[blockId][tmpVal];
                chunk[blockId].erase(it);
                --blockId;
            }
            while (blockId >= 0 && lb[blockId] >= l) {
                auto it = chunk[blockId].end(); --it;
                int newVal = chunk[blockId].back();
                chunk[blockId + 1].push_front(newVal);
                cnt[blockId + 1][newVal]++;
                chunk[blockId].pop_back();
                cnt[blockId][newVal]--;
                --blockId;
            }
            if (blockId >= 0 && rb[blockId] - 1 >= l) {
                int newVal = chunk[blockId].back();
                chunk[blockId + 1].push_front(newVal);
                cnt[blockId + 1][newVal]++;
                chunk[blockId].pop_back();
                cnt[blockId][newVal]--;
                int pos = rb[blockId];
                auto it = chunk[blockId].end();
                while (pos != l + 1) {
                    --pos, --it;
                }
                chunk[blockId].insert(it, tmpVal);
                cnt[blockId][tmpVal]++;
            } else {
                cnt[blockId + 1][tmpVal]++;
                chunk[blockId + 1].push_front(tmpVal);
            }
        } else {
            cin >> k;
            k = (k + lastans - 1) % n + 1;
            int ans = 0;
            for (int blockId = 0; blockId < allBl; ++blockId) {
                int cl = lb[blockId], cr = rb[blockId] - 1;
                if (l <= cl && r >= cr) {
                    ans += cnt[blockId][k];
                } else if (max(l, cl) <= min(r, cr)) {
                    int pos = cl;
                    for (auto it = chunk[blockId].begin(); pos <= cr; ++it, ++pos) {
                        if (pos >= l && pos <= r && *it == k) {
                            ++ans;
                        }
                    }
                }
            }
            lastans = ans;
            cout << ans << '\n';
        }
#ifdef DEBUG
        cerr << "operation complete" << endl;
        for (int i = 0; i < allBl; ++i) {
            cerr << "contents are:";
            for (auto x : chunk[i]) {
                cerr << " " << x;
            }
            cerr << endl;
        }
#endif
    }
    return 0;
}
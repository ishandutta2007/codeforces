#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <random>
#include <chrono>
#include <unordered_map>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

struct Tuple {
    int a[6];
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(Tuple x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((uint64_t)x.a[1] + FIXED_RANDOM) ^
            splitmix64((uint64_t)x.a[2] + FIXED_RANDOM) ^
            splitmix64((uint64_t)x.a[3] + FIXED_RANDOM) ^
            splitmix64((uint64_t)x.a[4] + FIXED_RANDOM) ^
            splitmix64((uint64_t)x.a[5] + FIXED_RANDOM);
    }
};

struct Segtree {
    int l, r;
    Segtree* lchild;
    Segtree* rchild;
    unordered_map<Tuple, int, custom_hash> mp;
};

Segtree* root;

int n, m;
Tuple a[100005];
Tuple tmpa[100005];
int w[100005];
int tupleseq[100005];
vector<pair<Tuple, int> > vec[100005];

bool operator==(Tuple A, Tuple b)
{
    for (int i = 1; i <= m; i++) {
        if (A.a[i] != b.a[i]) return false;
    }
    return true;
}

bool cmp(int x, int y)
{
    return w[x] < w[y];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        tupleseq[i] = i;
        vector<int> vect;
        for (int j = 1; j <= m; j++) {
            int tmp;
            scanf("%d", &tmp);
            vect.push_back(tmp);
        }
        sort(vect.begin(), vect.end());
        a[i].a[1] = vect[0];
        if (m >= 2) a[i].a[2] = vect[1];
        if (m >= 3) a[i].a[3] = vect[2];
        if (m >= 4) a[i].a[4] = vect[3];
        if (m >= 5) a[i].a[5] = vect[4];
        scanf("%d", w + i);
    }
    sort(tupleseq + 1, tupleseq + n + 1, cmp);
    sort(w + 1, w + n + 1);
    for (int i = 1; i <= n; i++) {
        tmpa[i] = a[tupleseq[i]];
    }
    for (int i = 1; i <= n; i++) {
        a[i] = tmpa[i];
    }
    unordered_map<Tuple, int, custom_hash> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < (1 << m); j++) {
            Tuple tup;
            tup.a[1] = tup.a[2] = tup.a[3] = tup.a[4] = tup.a[5] = -1;
            int curcnt = 0;
            for (int k = 0; k < m; k++) {
                if (!(j & (1 << k))) continue;
                curcnt++; tup.a[curcnt] = a[i].a[k + 1];
            }
            /*for (int k = 1; k <= m; k++) {
                printf("%d ", tup.a[k]);
            }
            printf("\n! %d\n", w[i]);*/
            vec[i].push_back(make_pair(tup, curcnt));
        }
    }
    vector<int> elems;
    int ans = 2000000001;
    for (int i = 1; i <= n; i++) {
        int last_popped = -1;
        while (!elems.empty()) {
            int tot = elems.size();
            for (int j = 0; j < vec[i].size(); j++) {
                int cnt = mp[vec[i][j].first];
                if (vec[i][j].second % 2) {
                    tot -= cnt;
                } else {
                    tot += cnt;
                }
            }
            if (tot > 0) {
                last_popped = elems.back();
                for (int j = 0; j < vec[last_popped].size(); j++) {
                    mp[vec[last_popped][j].first]--;
                }
                elems.pop_back();
            } else {
                break;
            }
        }
        if (last_popped != -1) {
            ans = min(ans, w[i] + w[last_popped]);
            for (int j = 0; j < vec[last_popped].size(); j++) {
                mp[vec[last_popped][j].first]++;
            }
            elems.push_back(last_popped);
        }
        for (int j = 0; j < vec[i].size(); j++) {
            mp[vec[i][j].first]++;
        }
        elems.push_back(i);
    }
    if (ans == 2000000001) {
        printf("-1");
    } else {
        printf("%d", ans);
    }
    return 0;
}
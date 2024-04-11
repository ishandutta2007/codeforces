#include <cstdio>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <queue>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct Query {
    int l, r, id;
};

unordered_map<int, int, custom_hash> dif[100005];
deque<int> pos[100005];
int difcnt[100005];
int periodcnt = 0;

int m;
int a[100005];
Query queries[100005];
int answer[100005];
int freq[100005];
int typecnt = 0;

bool cmp(Query A, Query b)
{
    if (A.l / 300 == b.l / 300) {
        return A.r < b.r;
    }
    return A.l < b.l;
}

void insert(int po, bool left)
{
    int val = a[po];
    if (!freq[val]) {
        typecnt++;
        if (difcnt[val] < 2) periodcnt++;
    }
    freq[val]++;
    int newdiff = -1;
    if (left) {
        if (!pos[val].empty()) {
            int pre = pos[val].front();
            newdiff = pre - po;
        }
        pos[val].push_front(po);
    } else {
        if (!pos[val].empty()) {
            int pre = pos[val].back();
            newdiff = po - pre;
        }
        pos[val].push_back(po);
    }
    if (newdiff != -1) {
        if (!dif[val][newdiff]) {
            if (difcnt[val] == 1) periodcnt--;
            difcnt[val]++;
        }
        dif[val][newdiff]++;
    }
}

void remove(int po, bool left)
{
    int val = a[po];
    int remdiff = -1;
    if (left) {
        pos[val].pop_front();
        if (!pos[val].empty()) {
            remdiff = pos[val].front() - po;
        }
    } else {
        pos[val].pop_back();
        if (!pos[val].empty()) {
            remdiff = po - pos[val].back();
        }
    }
    if (remdiff != -1) {
        if (dif[val][remdiff] == 1) {
            if (difcnt[val] == 2) periodcnt++;
            difcnt[val]--;
        }
        dif[val][remdiff]--;
    }
    if (freq[val] == 1) {
        typecnt--; if (difcnt[val] < 2) periodcnt--;
    }
    freq[val]--;
}

int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", a + i);
    }
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &queries[i].l, &queries[i].r);
        queries[i].id = i;
    }
    sort(queries + 1, queries + q + 1, cmp);
    insert(1, true);
    int l = 1, r = 1;
    for (int i = 1; i <= q; i++) {
        while (r < queries[i].r) insert(++r, false);
        while (l > queries[i].l) insert(--l, true);
        while (r > queries[i].r) remove(r--, false);
        while (l < queries[i].l) remove(l++, true);
        answer[queries[i].id] = typecnt + 1 - (periodcnt ? 1 : 0);
    }
    for (int i = 1; i <= q; i++) printf("%d\n", answer[i]);
    return 0;
}
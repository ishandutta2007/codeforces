#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) sz(s)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int MOD1 = int(1e9) + 7;
const int MOD2 = 42424243;

const int N = int(1e5) + 100;

struct hash {
    
    int a, b;
    
    hash() : a(0), b(0) {}
    
    hash(int a) : a(a), b(a) {}
    
    hash(int a, int b) : a(a), b(b) {}
    
};

hash operator + (const hash& a, const hash& b) {
    hash c(a.a + b.a, a.b + b.b);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    if (c.b >= MOD2) {
        c.b -= MOD2;
    }
    return c;
}

hash operator - (const hash& a, const hash& b) {
    hash c(a.a - b.a, a.b - b.b);
    if (c.a < 0) {
        c.a += MOD1;
    }
    if (c.b < 0) {
        c.b += MOD2;
    }
    return c;
}

hash operator * (const hash& a, const hash& b) {
    return hash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a && a.b == b.b;
}

bool operator < (const hash& a, const hash& b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }
    return a.b < b.b;
}

const hash X1(4243, 10007);
const hash X2(239017, int(2e5) + 3);

char buf[N];
hash hosts[N], queries[N];
string host[N], host2[N];
pair<hash, int> host_queries_hash[N];
vector<hash> host_queries[N];
vector<vi> groups;

inline hash calc(const char* s, int l, int r) {
    hash res;
    for (int i = l; i < r; ++i) {
        res = res * X1 + s[i];
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        int len = strlen(buf), ptr =  7;
        while (ptr < len && buf[ptr] != '/') {
            ++ptr;
        }
        host[i] = string(buf + 7, buf + ptr);
        hosts[i] = calc(buf, 7, ptr);
        queries[i] = calc(buf, ptr, len) + 42;
    }
    sort(hosts, hosts + n);
    int m = unique(hosts, hosts + n) - hosts;
    for (int i = 0; i < n; ++i) {
        hash host_hash = calc(host[i].data(), 0, sz(host[i]));
        int pos = lower_bound(hosts, hosts + m, host_hash) - hosts;
        host_queries[pos].pb(queries[i]);
        host2[pos] = host[i];
    }
    for (int i = 0; i < m; ++i) {
        sort(all(host_queries[i]));
        host_queries[i].resize(unique(all(host_queries[i])) - host_queries[i].begin());
        host_queries_hash[i].sc = i;
        for (hash query : host_queries[i]) {
            host_queries_hash[i].fs = host_queries_hash[i].fs * X2 + query;
        }
    }
    sort(host_queries_hash, host_queries_hash + m);
    int i = 0;
    while (i < m) {
        int j = i;
        while (j + 1 < m && host_queries_hash[j + 1].fs == host_queries_hash[i].fs) {
            ++j;
        }
        if (i < j) {
            vi group;
            for (int z = i; z <= j; ++z) {
                group.pb(host_queries_hash[z].sc);
            }
            groups.pb(group);
        }
        i = j + 1;
    }
    cout << sz(groups) << endl;
    for (const vi& group : groups) {
        for (int num : group) {
            printf("http://%s ", host2[num].data());
        }
        puts("");
    }
    return 0;
}
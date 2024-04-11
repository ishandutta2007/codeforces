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

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

ll a[50005];
ll b[50005];

int n, m; ll d;

vector<pair<ll, ll> > getseq(ll* seq, int len)
{
    vector<pair<ll, ll> > ans;
    for (int i = 1; i <= len; i++) {
        ll val = seq[i];
        while (val % d == 0) val /= d;
        if (ans.empty() || ans.back().first != val) {
            ans.push_back(make_pair(val, seq[i]));
        } else {
            ans[(int)(ans.size()) - 1].second += seq[i];
        }
    }
    return ans;
}

void work()
{
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%lld", b + i);
    vector<pair<ll, ll> > seq1 = getseq(a, n);
    vector<pair<ll, ll> > seq2 = getseq(b, m);
    /*for (int i = 0; i < seq1.size(); i++) {
        printf("%lld/%lld ", seq1[i].first, seq1[i].second);
    }
    printf("\n");
    for (int i = 0; i < seq2.size(); i++) {
        printf("%lld/%lld ", seq2[i].first, seq2[i].second);
    }*/
    if (seq1.size() != seq2.size()) {
        printf("No\n");
    } else {
        bool good = true;
        for (int i = 0; i < seq1.size(); i++) {
            if (seq1[i].first != seq2[i].first ||
                seq1[i].second != seq2[i].second) good = false;
        }
        printf("%s\n", good ? "Yes" : "No");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}
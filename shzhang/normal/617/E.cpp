#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

struct Query {
    int l, r, id;
};

int freq[4000005];
int a[100005];

int n, m, k;

Query queries[100005];
ll answ[100005];

ll ans = 0;

bool cmp(Query A, Query b)
{
    if (A.l / 300 == b.l / 300) {
        return A.r < b.r;
    }
    return A.l < b.l;
}

void insert(int val)
{
    freq[val]++;
    if (k == 0) {
        ans += freq[val] - 1;
    } else {
        ans += (ll)freq[val ^ k];
    }
}

void remove(int val)
{
    if (k == 0) {
        ans -= freq[val] - 1;
    } else {
        ans -= (ll)freq[val ^ k];
    }
    freq[val]--;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i] ^= a[i-1];
    }
    for (int i = 1; i <= m; i++) {
        int l, r; scanf("%d%d", &l, &r); l--;
        queries[i].l = l; queries[i].r = r; queries[i].id = i;
    }
    sort(queries + 1, queries + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        Query q = queries[i];
        while (q.l < l) insert(a[l-1]), l--;
        while (r < q.r) insert(a[r+1]), r++;
        while (l < q.l) remove(a[l]), l++;
        while (q.r < r) remove(a[r]), r--;
        answ[q.id] = ans;
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld\n", answ[i]);
    }
    return 0;
}
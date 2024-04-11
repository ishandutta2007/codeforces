#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>

using namespace std;

#define MOD 998244353
#define ll long long
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n;
pair<int, int> s[300005];
int factorial[300005];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int count_sortings(vector<int>& seq)
{
    int freq;
    int ans = 1;
    for (int i = 0; i < seq.size(); i++) {
        if (i == 0 || seq[i] != seq[i-1]) {
            freq = 1;
        } else {
            freq++;
        }
        if (i == seq.size() - 1 || seq[i] != seq[i+1]) {
            ans = mul(ans, factorial[freq]);
        }
    }

    return ans;
}

int main()
{
    scanf("%d", &n);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) factorial[i] = mul(factorial[i-1], i);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        s[i] = make_pair(a, b);
    }
    sort(s + 1, s + n + 1);
    int curcnt = 1;
    int total_abad = 1;
    int total_bbad = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || s[i].first != s[i-1].first) {
            curcnt = 1;
        } else {
            curcnt++;
        }
        if (i == n || s[i].first != s[i+1].first) {
            total_abad = mul(total_abad, factorial[curcnt]);
        }
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || s[i].second != s[i-1].second) {
            curcnt = 1;
        } else {
            curcnt++;
        }
        if (i == n || s[i].second != s[i+1].second) {
            total_bbad = mul(total_bbad, factorial[curcnt]);
        }
    }
    sort(s + 1, s + n + 1);
    vector<pair<int, int> > min_max;
    int cur = 1;
    int both_bad = 1;
    while (cur <= n) {
        int minval = 100000000;
        int maxval = 0;
        vector<int> vals;
        do {
            minval = min(minval, s[cur].second);
            maxval = max(maxval, s[cur].second);
            vals.push_back(s[cur].second);
            cur++;
        } while (cur <= n && s[cur].first == s[cur-1].first);
        sort(vals.begin(), vals.end());
        both_bad = mul(both_bad, count_sortings(vals));
        min_max.push_back(make_pair(minval, maxval));
    }
    /*for (int i = 0; i < min_max.size(); i++) {
        printf("%d %d\n", min_max[i].first, min_max[i].second);
    }*/
    for (int i = 1; i < min_max.size(); i++) {
        if (min_max[i-1].second > min_max[i].first) {
            both_bad = 0;
        }
    }
    //printf("%d %d %d %d\n", factorial[n], total_abad, total_bbad, both_bad);
    printf("%d", (int)(((((ll)factorial[n] - (ll)total_abad - (ll)total_bbad + (ll)both_bad) % MOD) + MOD) % MOD));
    return 0;
}
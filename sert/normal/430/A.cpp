#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>

#define y1 yy1
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

ll n, m;
string s;
pair<ll, ll> a[N];

bool cmp(pair<ll, ll> q, pair<ll, ll> t) {
    return q.second < t.second;
}

int len;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[len].first;
        a[len++].second = i;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++)
        a[i].first = i % 2;

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
        cout << a[i].first << " ";

    return 0;
}
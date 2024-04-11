#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

string s;
ll n, m, k, t, p;
ll a[N], b[N];
queue <pair<int, int> > q;
pair <int, int> h;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        q.push(make_pair(t, i + 1));
    }
    while (q.size() != !!q.size()) {
        h = q.front();
        q.pop();
        h.ff -= m;
        if (h.ff > 0)
            q.push(h);
    }
    cout << q.front().ss;
    return 0;
}
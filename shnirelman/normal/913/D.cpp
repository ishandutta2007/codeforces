#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int INF = 2e9;

mt19937 rnd(time(0));

int t[N], a[N];

bool cmp(const int& x, const int& y) {
    return a[x] < a[y];
}

bool cmp1(const int& x, const int& y) {
    return t[x] < t[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
    }

    vector<int> p(n);
    for(int i = 0; i < n; i++)
        p[i] = i;

    sort(p.begin(), p.end(), cmp);

    int lf = 0, rg = n + 1;
    while(rg - lf > 1) {
        int mid = (lf + rg) / 2;

        int l = -1, r = n;
        while(r - l > 1) {
            int mid1 = (l + r) / 2;

            if(a[p[mid1]] < mid)
                l = mid1;
            else
                r = mid1;
        }

        l++;

        vector<int> q(n - l);
//        cout << mid << ' ' << q.size() << endl;
        for(int i = l; i < n; i++)
            q[i - l] = p[i];

        sort(q.begin(), q.end(), cmp1);

        int res = 0, s = 0;
        for(int i = 0; i < q.size(); i++) {
            s += t[q[i]];
            if(s > m)
                break;
            res++;
        }

        if(res >= mid)
            lf = mid;
        else
            rg = mid;
    }

    cout << lf << endl;

    int l = -1, r = n;
    while(r - l > 1) {
        int mid1 = (l + r) / 2;

        if(a[p[mid1]] < lf)
            l = mid1;
        else
            r = mid1;
    }


    l++;

    vector<int> q(n - l);
//    cout << lf << ' ' << q.size() << endl;
    for(int i = l; i < n; i++)
        q[i - l] = p[i];

    sort(q.begin(), q.end(), cmp1);

    int s = 0;
    vector<int> ans;
    for(int i = 0; i < lf; i++) {
        s += t[q[i]];
        if(s > m)
            break;
        ans.push_back(q[i]);
    }

    cout << ans.size() << endl;
    for(auto an : ans)
        cout << an + 1 << ' ';
}
#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int n, k, ps, pf;
pair <int, int> a[N];
vector <pair <int, int> > ans;

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    while (k --> 0) {
        if (a[0].first + 1 >= a[n - 1].first)
            break;
        ps = 0;
        while (a[ps].first == a[ps + 1].first)
            ps++;
        pf = n - 1;
        while (a[pf].first == a[pf - 1].first)
            pf--;
        a[ps].first++;
        a[pf].first--;
        ps = a[ps].second;
        pf = a[pf].second;
        ans.push_back(make_pair(pf, ps));
    }
    cout << a[n - 1].first - a[0].first << " " << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    //return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

int n;
int a[N];
map < int, int > cnt;
set < pair < int, int > > was;

int go(int x, int y) {
    if (was.count(mp(x, y))) {
        return 0;
    }
    was.insert(mp(x, y));
    vector < int > have;
    have.push_back(x);
    have.push_back(y);
    cnt[x]--;
    cnt[y]--;
    while (true) {
        int z = x + y;
        if (abs(z) > 1e+9 || cnt[z] == 0) {
            break;
        }
        have.push_back(z);
        cnt[z]--;
        x = y;
        y = z;
    }
    int res = have.size();
    for (int i = 0; i < res; ++i)
        cnt[have[i]]++;
    return res;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], cnt[a[i]]++;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] == 0 && a[j] == 0) {
                ans = max(ans, cnt[0]);
                continue;
            }
            ans = max(ans, go(a[i], a[j]));
            ans = max(ans, go(a[j], a[i]));
        }
    }
    cout << ans << endl;
    return 0;
}
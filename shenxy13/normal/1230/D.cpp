#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    ll a[n], b[n], ans = 0;
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
    unordered_map<ll, int> skills;
    for (int i = 0; i < n; ++i) skills[a[i]] += 1;
    vector<ll> dom;
    for (pair<ll, ll> i: skills) {
        if (i.second > 1) dom.push_back(i.first);
    }
    for (int i = 0; i < n; ++i) {
        bool use = false;
        for (int j = 0; j < dom.size(); ++j) {
            if ((dom[j] | a[i]) == dom[j]) {
                use = true;
                break;
            }
        }
        if (use) ans += b[i];
    }
    printf("%lld", ans);
    return 0;
}
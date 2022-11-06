#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define int long long
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> ma;
    while (n--) {
        int a;
        cin >> a;
        ma[a]++;
    }
    for (auto el : ma) if (el.sc & 1) {
        cout << "Conan";
        return 0;
    }
    cout << "Agasa";
    return 0;
}
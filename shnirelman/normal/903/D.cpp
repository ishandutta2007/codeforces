//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

//        mp[a[i]]++;
    }
//return 0;
//    sort(a.begin(), a.end());

    li s = 0;
    __int128 ans = 0;
    for(int i = 0; i < n; i++) {
        int c1 = mp[a[i] + 1], c0 = mp[a[i]], c_1 = mp[a[i] - 1];
        int cnt = i - c0 - c1 - c_1;
        ans += a[i] * 1ll * cnt - s + c0 * 1ll * a[i] + c1 * 1ll * (a[i] + 1) + c_1 * 1ll * (a[i] - 1);
        mp[a[i]]++;
        s += a[i];
    }
    
    if(ans == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    if(ans < 0) {
        cout << '-';
        ans *= -1;
    }
    
    string t = "";
    while(ans > 0) {
        t += '0' + ans % 10;
        ans /= 10;
    }
    
    reverse(t.begin(), t.end());

    cout << t << endl;
    
    
}
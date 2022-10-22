#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using  pii = pair<int, int>;

const int N = 2e5 + 13;

int cnt[N];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;


    int n = s.length();

    int q;
    cin >> q;

    vector<int> a(q);
    for(int i = 0; i < q; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }

    string r = s;
    reverse(r.begin(), r.end());

    int cur = 0;

    string ans = s;
    for(int i = 0; i < n / 2; i++) {
        cur += cnt[i];
        if(cur % 2 == 0) {
            ans[i] = s[i];
            ans[n - i - 1] = s[n - i - 1];
        } else {
            ans[i] = r[i];
            ans[n - i - 1] = r[n - i - 1];
        }



    }

    cout << ans;


}
#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using  pii = pair<int, int>;

const int N = 256;

int cnt[N];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        cnt[s[i * 2] - 'a']++;
        if(cnt[s[i * 2 + 1] - 'A'])
            cnt[s[i * 2 + 1] - 'A']--;
        else
            ans++;
    }

    cout << ans << endl;
}
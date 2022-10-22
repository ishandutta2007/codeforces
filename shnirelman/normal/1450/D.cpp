#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 3e5 + 13;

int a[N];
vector<int> pos[N];
bool ans[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        pos[i].erase(pos[i].begin(), pos[i].end());
        ans[i] = false;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        pos[a[i]].push_back(i);
    }


    int mn = 1;
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++) {
        if(pos[i].size() == 0) {
//            for(int j = 0; j < n; j++)
//                cout << 0;
//            cout << endl;
//            return;
            break;
        }
        ans[n - i - 1] = true;

        if(pos[i].size() == 1 && pos[i][0] == l || pos[i][0] == r) {
            if(pos[i][0] == l)
                l++;
            else
                r--;
        } else {
            break;
        }
    }

    ans[0] = true;
    for(int i = 0; i < n; i++) {
        if(pos[i].size() != 1)
            ans[0] = false;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}
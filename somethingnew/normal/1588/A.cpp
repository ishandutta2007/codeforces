#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> ex(205), cnt(205);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;x+=100;
        cnt[x]++;
        ex[x]++;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;x+=100;
        cnt[x]--;
    }
    for (int i = 0; i < 205; ++i) {
        if (cnt[i] < 0) {
            cout << "NO\n";
            return;
        }
        if (cnt[i] > 0) {
            if (ex[i] >= cnt[i]) {
                cnt[i + 1] += cnt[i];
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt[2];
string win[2] = {"Daenerys", "Stannis"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; cnt[a%2]++;
    }

    if(n - k == 0) {
        cout << win[cnt[1] % 2] << endl;
    }
    else if((n - k) % 2 == 0) {
        if((n - k) / 2 >= cnt[0] && k % 2 == 1) cout << win[1] << endl;
        else cout << win[0] << endl;
    }
    else {
        if((n - k) / 2 >= cnt[1] || ((n - k) / 2 >= cnt[0] && k % 2 == 0)) cout << win[0] << endl;
        else cout << win[1] << endl;
    }
}
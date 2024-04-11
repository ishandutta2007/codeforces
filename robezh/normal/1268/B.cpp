#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

int n;
int a[N];
ll cnt[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            cnt[0] += a[i] / 2;
            cnt[1] += a[i] - a[i] / 2;
        }
        else {
            cnt[0] += a[i] - a[i] / 2;
            cnt[1] += a[i] / 2;
        }
    }
    cout << min(cnt[0], cnt[1]) << endl;
}
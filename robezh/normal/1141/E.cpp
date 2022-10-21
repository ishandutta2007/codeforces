#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

ll H;
int n;
int d[N];
ll mn = 0;
ll sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> n;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        cur += d[i];
        mn = min(mn, cur);
        sum += d[i];
    }
    if(H + mn > 0 && sum >= 0) return !printf("-1");
    ll round;
    if(H + mn <= 0) round = 0;
    else {
        sum = -sum;
        round = (H + mn) / sum;
    }
    ll cur_r = round * n;
    H -= round * sum;
    while(true) {
        H += d[cur_r % n];
        cur_r++;
        if (H <= 0) break;
    }
    cout << cur_r << endl;

}
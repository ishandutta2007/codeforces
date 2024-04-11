#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 20005;

int n;
int odd[N];
int a[N], b[N];

int round_down(int x) {
    if(x % 2 != 0) return (x - 1) / 2;
    else return x / 2;
}

int main() {
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = round_down(a[i]);
        sum += b[i];
    }

    for(int i = 0; i < n; i++) {
        if(sum < 0 && a[i] % 2 != 0) {
            sum++;
            b[i]++;
        }
    }
    for(int i = 0; i < n; i++) cout << b[i] << '\n';
//    cout << sum << '\n';
}
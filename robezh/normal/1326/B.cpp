#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)2e5 + 50;


int n;
int b[N], a[N], mx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        a[i] = mx + b[i];
        mx = max(a[i], mx);
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


}
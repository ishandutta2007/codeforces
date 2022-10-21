#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n, a[N];

int main() {
    cin >> n;
    int cnt[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] % 2] ++;
    }
    if(cnt[1] > 0 && cnt[0] > 0) sort(a, a + n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";

}
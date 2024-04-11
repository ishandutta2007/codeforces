#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n;
int p[N], res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 2; i <= n; i++) p[i] = i;
    int cnt = 1;
    for(int i = 2; i <= n; i++) {
        if(p[i] != i) {
            res[i] = res[p[i]];
            continue;
        }
        for(int j = 2 * i; j <= n; j += i) p[j] = i;
        res[i] = cnt++;
    }
    for(int i = 2; i <= n; i++) cout << res[i] << " ";

}
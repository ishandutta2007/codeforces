#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50;

int n;
int x[N], y[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> x[i] >> y[i];
    printf("YES\n");
    for(int i = 0; i < n; i++) printf("%d\n", (x[i] % 2 + 2) % 2 + (y[i] % 2 + 2) % 2 * 2 + 1);
}
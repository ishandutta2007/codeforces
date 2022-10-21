#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;
typedef long long ll;

int n,m;
ll num[N], res[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%I64d", &num[i]);
    for(int i = 1; i < n; i++) num[i] += num[i-1];
    for(int i = 0; i < n; i++) res[i] = (num[i]) / m;
    for(int i = n-1; i >= 1; i--) res[i] -= res[i-1];
    for(int i = 0; i < n; i++) printf("%I64d ", res[i]);
}
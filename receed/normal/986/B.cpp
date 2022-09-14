#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 1 << 20;
int tr[N * 2];

void add(int v) {
    for (int i = N + v; i; i /= 2)
        tr[i]++;
}

int sum(int cl, int cr, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl)
        return 0;
    if (cl <= l && r <= cr)
        return tr[v];
    return sum(cl, cr, v * 2, l, (l + r) / 2) + sum(cl, cr, v * 2 + 1, (l + r) / 2, r);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    ll s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        s += sum(t + 1, N);
        add(t);
    }
    if (s % 2 == n % 2)
        printf("Petr");
    else
        printf("Um_nik");
}
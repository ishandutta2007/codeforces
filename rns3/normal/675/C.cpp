#include <bits/stdc++.h>
using namespace std;

map<long long, int> mp;

int main() {
    //freopen("b.in", "r", stdin);
    int n;
    scanf("%d", &n);
    long long y = 0;
    int mx = 0;
    for(int i =  1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        y += x;
        mp[y] ++;
        mx = max(mx, mp[y]);
    }
    printf("%d\n", n - mx);
}
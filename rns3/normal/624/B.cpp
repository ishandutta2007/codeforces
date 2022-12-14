#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int a[101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    long long sum = 0;
    for(int i = n; i; i --) {
        int x = a[i];
        while(mp[x] && x > 0) x --;
        if(!x) break;
        sum += x;
        mp[x] = 1;
    }
    cout << sum << endl;
}
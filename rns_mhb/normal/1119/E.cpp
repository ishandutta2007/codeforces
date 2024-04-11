#include<bits/stdc++.h>
using namespace std;

#define N 300010

int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    vector <int> v;
    for(int i = 0; i < n; i ++) if(a[i] & 1) v.push_back(i);
    for(int i = 0; i < n; i ++) a[i] /= 2;
    long long ans = 0;
    for(int i = n-1; i >= 0; i --) {
        while(!v.empty() && v.back() > i) v.pop_back();
        int mn = min((int)v.size(), a[i]);
        a[i] -= mn;
        ans += mn;
        while(mn --) v.pop_back();
        if(v.empty()) {
            long long cur = 0;
            for(int j = 0; j <= i; j ++) cur += 2 * a[j];
            ans += cur / 3;
            break;
        }
    }
    printf("%I64d\n", ans);
}
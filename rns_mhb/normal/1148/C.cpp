#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 300010

int a[N], p[N];

void Swap(int i, int j) {
    swap(p[i], p[j]);
    a[p[i]] = i, a[p[j]] = j;
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n >> 1;
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]), a[p[i]] = i;
    vector <pii> ans;
    for(int i = 1; i <= m; i ++) {
        int x = a[i];
        if(x == i) continue;
        if(x > m) {
            if(i != 1) {
                if(x != n) {
                    ans.push_back(pii(1, x)); Swap(1, x);
                    ans.push_back(pii(1, n)); Swap(1, n);
                    ans.push_back(pii(1, x)); Swap(1, x);
                    ans.push_back(pii(i, n)); Swap(i, n);
                }
                if(x == n) {
                    ans.push_back(pii(i, x)); Swap(i, x);
                }
            }
            else {
                ans.push_back(pii(1, x)); Swap(1, x);
            }
        }
        else {
            ans.push_back(pii(x, n)); Swap(x, n);
            ans.push_back(pii(i, n)); Swap(i, n);
        }
    }
    for(int i = m + 1; i <= n; i ++) {
        int x = a[i];
        if(x == i) continue;
        ans.push_back(pii(1, x)); Swap(1, x);
        ans.push_back(pii(1, i)); Swap(1, i);
        ans.push_back(pii(1, x)); Swap(1, x);
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i ++) printf("%d %d\n", ans[i].first, ans[i].second);
}
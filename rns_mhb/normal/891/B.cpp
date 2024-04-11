#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 30

int a[N], b[N];
pii p[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) p[i] = pii(a[i], i);
    sort(p+1, p+n+1);
    for(int i = 1; i <= n; i ++) b[p[i].second] = p[i%n+1].second;
    for(int i = 1; i <= n; i ++) cout << a[b[i]] << ' ';
}
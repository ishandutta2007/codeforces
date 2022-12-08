#include<bits/stdc++.h>
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 2e5 + 5, P = 998244353;
int n, m, ans;
int a[N], b[N];
map<int, int> bin;

int main() {
    n = get(), m = get();
    for(int i = 1; i <= n; i++) a[i] = get();
    for(int i = 1; i <= m; i++) b[i] = get();
    for(int i = n - 1; i >= 1; i--) a[i] = min(a[i], a[i + 1]), bin[a[i]]++; bin[a[n]]++;
    ans = (a[1] == b[1]);
    for(int i = 2; i <= m; i++) ans = 1ll * ans * bin[b[i]] % P;
    printf("%d", ans); 
    return 0;
}
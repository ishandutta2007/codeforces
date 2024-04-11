#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll b[200010];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%I64d", &b[i]);
    vector <ll> v[111];
    for(int i = 1; i <= n; i ++) {
        v[__builtin_ctzll(b[i])].push_back(b[i]);
    }
    int mx = -1, p;
    for(int i = 0; i < 100; i ++) {
        if((int)v[i].size() > mx) mx = v[i].size(), p = i;
    }
    printf("%d\n", n - mx);
    for(int i = 0; i < 111; i ++) if(i != p) {
        for(int j = 0; j < v[i].size(); j ++) printf("%I64d ", v[i][j]);
    }
}
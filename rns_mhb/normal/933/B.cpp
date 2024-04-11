#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <int> v;

bool solve(ll p, int k, bool sgn) {
    if(p == 0) return 1;
    if(p < 0) return 0;
    if(!sgn) {
        v.push_back(p % k);
        return solve(p / k, k, !sgn);
    }
    if(sgn) {
        int x = (k - p % k) % k;
        v.push_back(x);
        return solve((p + x) / k, k, !sgn);
    }
}

int main() {
    ll p;
    int k;
    scanf("%I64d%d", &p, &k);
    if(!solve(p, k, 0)) puts("-1");
    else {
        printf("%d\n", v.size());
        for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]); puts("");
    }
}
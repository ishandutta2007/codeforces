#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, kk;
int m[202][202][202];
string s, t;

int solve1() {
    int nota = 0;
    int a = 0;
    for (char c:s) {
        nota+=c!=t[0];
        a+=c==t[0];
    }
    a+=min(nota, kk);
    return (a*(a-1))/2;
}

int f(int p, int k, int a) {
    if (p == n)
        return 0;
    int &r = m[p][k][a];
    if(r!=-1) return r;
    r = (s[p]==t[1]?a:0) + f(p+1, k, a+(s[p]==t[0]?1:0));
    if (k>0) {
        r = max(r, f(p+1, k-1, a+1));
        r = max(r, a + f(p+1, k-1, a));
    }
    return r;
}

int solve2() {
    return f(0, kk, 0);
}

int main() {
    setIO();
    cin>>n>>kk;
    cin>>s>>t;
    int r = 0;
    if (t[0] == t[1]) {
        r = solve1();
    } else {
        memset(m, -1, sizeof(m));
        r = solve2();
    }
    cout<<r<<endl;
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
long long n, q;
char s[1000005];

struct Data{
    int open, close, ok;
    Data operator + (Data &other) {
        int sl = min(open, other.close);
        int _open = open + other.open - sl;
        int _close = close + other.close - sl;
        int _ok = ok + other.ok + sl;
        return {_open, _close, _ok};
    }
} f[2000005];

void build() {
    Data x();
    for(int i = n-1; i; i--)
        f[i] = f[i<<1] + f[i<<1|1];
}

void Enter() {
    cin >> s;
    n = strlen(s);
    for(int i=0; i<n; i++) {
        if (s[i] == '(') ++f[i+n].open;
            else ++f[i+n].close;
    }
    build();
}

long long query(int l, int r) {
    Data resl = {0,0,0}, resr = {0,0,0};
    for(l += n - 1, r += n; l<r; l>>=1, r>>=1) {
        if (l&1) resl = resl + f[l++];
        if (r&1) resr = f[--r] + resr;
    }
    return (resl + resr).ok * 2;
}

void Process() {
    cin >> q;
    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
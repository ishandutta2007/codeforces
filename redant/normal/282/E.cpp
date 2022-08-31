#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}


const int SIZE = 2;
const int BITS = 42;

struct TNode {
    TNode *child[SIZE] = {};
    int cnt = 0;
    
    void insert(LL val) {
        TNode *cur = this;
        cur->cnt++;
        for (int i = BITS; i >= 0; i--) {
            int b = val >> i & 1;
            if (cur->child[b] == nullptr)
                cur->child[b] = new TNode();
            cur = cur->child[b];
            cur->cnt++;
        }
    }

    void remove(LL val) {
        TNode *cur = this;
        cur->cnt--;
        for (int i = BITS; i >= 0; i--) {
            int b = val >> i & 1;
            cur = cur->child[b];
            cur->cnt--;
        }
    }
    
    LL maxXor(LL val) {
        LL r = 0;
        TNode *cur = this;
        for (int i = BITS; i >= 0 && cur; i--) {
            int b = 1 - (val >> i & 1);
            if (cur->child[b] && cur->child[b]->cnt) {
                r += 1ll << i;
                cur = cur->child[b];
            } else {
                cur = cur->child[1-b];
            }
        }
        return r;
    }
};

const int MX = 100005;
LL a[MX];
int n;

LL solve() {
    TNode root;
    LL prex = 0;
    root.insert(0);
    REP(i, n) {
        prex ^= a[i+1];
        root.insert(prex);
    }
    LL r = root.maxXor(0);
    LL postx = 0;
    for (int i = n; i > 0; i--) {
        root.remove(prex);
        postx ^= a[i];
        r = max(r, root.maxXor(postx));
        prex ^= a[i];
    }
    return r;
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>a[i+1];
    }
    cout<<solve()<<"\n";    
    return 0;
}
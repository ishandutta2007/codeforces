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
const int BITS = 20;

struct TNode {
    TNode *child[SIZE] = {};
    int cnt = 0;

    void insert(int val) {
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
    
    int mexXor(int val) {
        int r = 0;
        TNode *cur = this;
        for (int i = BITS; i >= 0 && cur; i--) {
            int b = (val >> i & 1);
            if(cur->child[b] == nullptr)
                break;
            if (cur->child[b]->cnt < (1<<i)) {
                cur = cur->child[b];
            } else {
                r += 1 << i;
                cur = cur->child[1-b];
            }
        }
        return r;
    }
};

int n, q;

int main() {
    setIO();
    cin>>n>>q;
    TNode root;
    int x;
    set<int> s;
    REP(i, n) {
        cin>>x;
        if (s.insert(x).second)
            root.insert(x);
    }
    int v = 0;
    while(q--) {
        cin>>x;
        v ^= x;
        cout<<root.mexXor(v)<<"\n";
    }
    
    return 0;
}
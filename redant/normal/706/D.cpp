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
const int BITS = 30;

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

    void remove(int val) {
        TNode *cur = this;
        cur->cnt--;
        for (int i = BITS; i >= 0; i--) {
            int b = val >> i & 1;
            cur = cur->child[b];
            cur->cnt--;
        }
    }
    
    int maxXor(int val) {
        int r = 0;
        TNode *cur = this;
        for (int i = BITS; i >= 0 && cur; i--) {
            int b = 1 - (val >> i & 1);
            if (cur->child[b] && cur->child[b]->cnt) {
                r += 1 << i;
                cur = cur->child[b];
            } else {
                cur = cur->child[1-b];
            }
        }
        return r;
    }
};

int main() {
    setIO();
    int q; cin>>q;
    char op; int x;
    TNode root;

    root.insert(0);
    while(q--) {
        cin>>op>>x;
        if (op == '+') root.insert(x);
        else if (op == '-') root.remove(x);
        else cout<<root.maxXor(x)<<"\n";
    }
    
    return 0;
}
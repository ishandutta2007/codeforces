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
const int BITS = 17;

struct TNode {
    TNode *child[SIZE] = {};
    int cnt = 0;
    
    void insert(string &s) {
        TNode *cur = this;
        cur->cnt++;
        for (int i = BITS; i >= 0; i--) {
            int b = (s[i]-'0')%2;
            if (cur->child[b] == nullptr)
                cur->child[b] = new TNode();
            cur = cur->child[b];
            cur->cnt++;
        }
    }

    void remove(string &s) {
        TNode *cur = this;
        cur->cnt--;
        for (int i = BITS; i >= 0; i--) {
            int b = (s[i]-'0')%2;
            cur = cur->child[b];
            cur->cnt--;
        }
    }
    
    int getCount(string &s) {
        TNode *cur = this;
        for (int i = BITS; i >= 0 && cur; i--) {
            int b = (s[i]-'0')%2;
            if (cur->child[b] && cur->child[b]->cnt) {
                cur = cur->child[b];
            } else {
                return 0;
            }
        }
        return cur->cnt;
    }
    
    // Count ? ^ val < lim
    int countLess(int val, int lim) {
        int r = 0;
        TNode *cur = this;
        for (int i = BITS; i >= 0 && cur; i--) {
            int bv = val >> i & 1;
            int bl = lim >> i & 1;
            if (bl == 0) {
                cur = cur->child[bv];
                continue;
            } else {
                if (cur->child[bv] != nullptr)
                    r += cur->child[bv]->cnt;
                cur = cur->child[1-bv];
            }
        }
        return r;
    }
};

int main() {
    setIO();
    int q; cin>>q;
    char op; string s;
    TNode root;
    REP(i, q) {
        cin>>op>>s;
        s = string(18-s.size(), '0') + s;
        // cout << i << " s = " << s << "\n";`
        if (op == '+') root.insert(s);
        else if (op == '-') root.remove(s);
        else cout << root.getCount(s) << "\n";
    }    
    return 0;
}
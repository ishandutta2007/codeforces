    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    struct node {
        int l, r, mi, ma, la;
        node *left, *right;
     
        int get_ma() { return ma + la; }
        int get_mi() { return mi + la; }
        void merge() {
            mi = min(left->get_mi(), right->get_mi());
            ma = max(left->get_ma(), right->get_ma());
        }
        void push() {
            left->la += la;
            right->la += la;
            la = 0;
        }
        node(int l, int r) : l(l), r(r), la(0), mi(0), ma(0) {
            if(l < r) {
                int m = (l + r)/2;
                left = new node(l, m);
                right = new node(m + 1, r);
            }
        }
        void upd(int rl, int rr, int v) {
            if(r < rl || rr < l)
                return;
            if(rl <= l && r <= rr) {
                la += v;
                return;
            }
            push();
            left->upd(rl, rr, v);
            right->upd(rl, rr, v);
            merge();
        }
    };
     
    const int MAXN = 1e6 + 5;
    int va[MAXN];
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int n, p = 0, sum = 0;
        cin >> n;
        node tree(0, MAXN);
        string s;
        cin >> s;
        for(auto c : s) {
            if(c == 'R')
                p++;
            else if(c == 'L')
                p -= (p > 0);
            else if(c == '(') {
                tree.upd(p, MAXN, 1 - va[p]);
                sum += 1 - va[p];
                va[p] = 1;
            }
            else if(c == ')') {
                tree.upd(p, MAXN, -1 - va[p]);
                sum += -1 - va[p];
                va[p] = -1;
            }
            else {
                tree.upd(p, MAXN, -va[p]);
                sum += -va[p];
                va[p] = 0;
            }
            if(sum != 0 || tree.get_mi() < 0)
                cout << "-1 ";
            else
                cout << tree.get_ma() << ' ';
        }
        cout << '\n';
    }////
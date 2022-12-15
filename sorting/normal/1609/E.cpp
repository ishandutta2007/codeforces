#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 3;

int n, q;
string s;

struct SegmentTree{
    struct Node{
        int a, b, c;
        int ab, bc;
        int abc;

        Node(){}
        Node(char ch){
            if(ch == 'a'){
                a = 1;
                b = c = 0;
                ab = bc = 0;
                abc = 0;
            }
            else if(ch == 'b'){
                b = 1;
                a = c = 0;
                ab = bc = 0;
                abc = 0;
            }
            else{
                c = 1;
                a = b = 0;
                ab = bc = 0;
                abc = 0;
            }
        }

        friend Node merge(Node l, Node r){
            Node ret;
            ret.a = l.a + r.a;
            ret.b = l.b + r.b;
            ret.c = l.c + r.c;
            ret.ab = min(l.ab + r.b, r.ab + l.a);
            ret.bc = min(r.bc + l.b, l.bc + r.c);
            ret.abc = min({l.abc + r.c, r.abc + l.a, l.ab + r.bc});
            return ret;
        }
    };

    Node nd[4 * N];

    void update(int idx, char c, int i = 0, int l = 0, int r = n - 1){
        if(r < idx || idx < l) return;
        if(l == r){
            nd[i] = Node(c);
            return;
        }
        int mid = (l + r) >> 1;
        update(idx, c, 2 * i + 1, l, mid);
        update(idx, c, 2 * i + 2, mid + 1, r);
        nd[i] = merge(nd[2 * i + 1], nd[2 * i + 2]);
        //cout << nd[i].c << " nd" << endl;
    }

    int query(){
        //cout << nd[0].c << " c" << endl;
        return min({nd[0].abc, nd[0].a, nd[0].b, nd[0].c});
    }
} st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    cin >> s;
    for(int i = 0; i < n; ++i)
        st.update(i, s[i]);
    //cout << st.nd[0].c << endl;

    for(int i = 0; i < q; ++i){
        int pos;
        char c;
        cin >> pos >> c;
        --pos;

        st.update(pos, c);
        cout << st.query() << "\n";
    }
}
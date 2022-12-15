#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

struct Node{
    Node *p = 0, *pp = 0, *c[2];
    bool flip = 0;
    Node(){ c[0] = c[1] = 0; fix(); }
    void fix(){
        if(c[0]) c[0]->p = this;
        if(c[1]) c[1]->p = this;
        // (+ update sum of subtree elements etc. if wanted)
    }
    void pushFlip(){
        if(!flip) return;
        flip = 0; swap(c[0], c[1]);
        if(c[0]) c[0]->flip ^= 1;
        if(c[1]) c[1]->flip ^= 1;
    }
    int up(){ return p ? p->c[1] == this : -1; }
    void rot(int i, int b){
        int h = i ^ b;
        Node *x = c[i], *y = b == 2 ? x : x->c[h], *z = b ? y : x;
        if((y->p = p)) p->c[up()] = y;
        c[i] = z->c[i ^ 1];
        if(b < 2){
            x->c[h] = y->c[h ^ 1];
            z->c[h ^ 1] = b ? x : this;
        }
        y->c[i ^ 1] = b ? this : x;
        fix(); x->fix(); y->fix();
        if(p) p->fix();
        swap(pp, y->pp);
    }
    void splay(){
        for(pushFlip(); p; ){
            if(p->p) p->p->pushFlip();
            p->pushFlip(); pushFlip();
            int c1 = up(), c2 = p->up();
            if(c2 == -1) p->rot(c1, 2);
            else p->p->rot(c2, c1 != c2);
        }
    }
    Node* first(){
        pushFlip();
        return c[0] ? c[0]->first() : (splay(), this);
    }
};

struct LinkCut{
    vector<Node> node;
    LinkCut(int N): node(N){}

    void link(int u, int v){ // add an edge (u, v)
        // cout << "link " << u << " " << v << endl;
        assert(!connected(u, v));
        makeRoot(&node[u]);
        node[u].pp = &node[v];
    }
    void cut(int u, int v){ // remove and edge (u, v)
        Node *x = &node[u], *top = &node[v];
        makeRoot(top); x->splay();
        assert(top == (x->pp ? : x->c[0]));
        if(x->pp) x->pp = 0;
        else{
            x->c[0] = top->p = 0;
            x->fix();
        }
    }
    bool connected(int u, int v){ // are u, v in the same tree?
        Node *nu = access(&node[u])->first();
        return nu == access(&node[v])->first();
    }
    void makeRoot(Node *u){
        access(u);
        u->splay();
        if(u->c[0]){
            u->c[0]->p = 0;
            u->c[0]->flip ^= 1;
            u->c[0]->pp = u;
            u->c[0] = 0;
            u->fix();
        }
    }
    Node* access(Node *u){
        u->splay();
        while(Node *pp = u->pp){
            pp->splay(); u->pp = 0;
            if(pp->c[1]){
                pp->c[1]->p = 0;
                pp->c[1]->pp = pp;
            }
            pp->c[1] = u;
            pp->fix();
            u = pp;
        }
        return u;
    }
};

const int N = 1003;
const int MAX = 2e5 + 3;

int n, m, a[N][N];
bool active[MAX];
pair<int, int> pos[MAX];
LinkCut link_cut(0);

array<int, 2> adj[4]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool in_table(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void rem(int num){
    auto [x, y] = pos[num];
    for(auto [dx, dy]: adj){
        auto [to_x, to_y] = pair{x + dx, y + dy};
        if(!in_table(to_x, to_y))
            continue;

        int to = a[to_x][to_y];
        if(active[to]){
            link_cut.cut(num, to);
        }
    }

    active[num] = false;
}

void add(int &l, int num){
    auto [x, y] = pos[num];
    for(auto [dx, dy]: adj){
        auto [to_x, to_y] = pair{x + dx, y + dy};
        if(!in_table(to_x, to_y))
            continue;

        int to = a[to_x][to_y];
        if(active[to]){
            while(link_cut.connected(num, to)){
                rem(l);
                ++l;
            }
            link_cut.link(num, to);
        }
    }

    active[num] = true;
}

struct SegmentTree{
    struct Node{
        int mx, cnt;
    
        Node(){}
        Node(int mx, int cnt): mx(mx), cnt(cnt){}
        friend Node merge(Node l, Node r){
            Node res;
            res.mx = max(l.mx, r.mx);
            res.cnt = 0;
            res.cnt += (l.mx == res.mx) ? l.cnt : 0;
            res.cnt += (r.mx == res.mx) ? r.cnt : 0;
            return res;
        }
    };

    Node nd[4 * MAX];
    int lp[4 * MAX];

    void build(int i = 0, int l = 1, int r = MAX - 1){
        if(l == r){
            nd[i] = Node(0, 1);
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, r);
        nd[i] = merge(nd[2 * i + 1], nd[2 * i + 2]);
    }

    void push_lazy(int i, int l, int r){
        if(!lp[i]) return;
        nd[i].mx += lp[i];
        if(l != r){
            lp[2 * i + 1] += lp[i];
            lp[2 * i + 2] += lp[i];
        }
        lp[i] = 0;
    }

    void update(int sl, int sr, int val, int i = 0, int l = 1, int r = MAX - 1){
        push_lazy(i, l, r);
        if(sr < l || r < sl) return;
        if(sl <= l && r <= sr){
            lp[i] += val;
            push_lazy(i, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(sl, sr, val, 2 * i + 1, l, mid);
        update(sl, sr, val, 2 * i + 2, mid + 1, r);
        nd[i] = merge(nd[2 * i + 1], nd[2 * i + 2]);
    }

    Node query(int sl, int sr, int i = 0, int l = 1, int r = MAX - 1){
        push_lazy(i, l, r);
        if(sr < l || r < sl) return Node(-1, 0);
        if(sl <= l && r <= sr) return nd[i];

        int mid = (l + r) >> 1;
        Node ln = query(sl, sr, 2 * i + 1, l, mid);
        Node rn = query(sl, sr, 2 * i + 2, mid + 1, r);
        return merge(ln, rn);
    }
} st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            pos[a[i][j]] = {i, j};
        }

    link_cut = LinkCut(n * m + 1);

    st.build();
    for(int i = 2; i <= n * m; ++i)
        st.update(i, n * m, 1);

    int l = 1;
    ll ans = 0;
    for(int r = 1; r <= n * m; ++r){
        add(l, r);

        auto [x, y] = pos[r];
        for(auto [dx, dy]: adj){
            auto [to_x, to_y] = pair{x + dx, y + dy};
            if(!in_table(to_x, to_y))
                continue;

            int to = a[to_x][to_y];
            if(to <= r){
                st.update(1, to, 1);
            }
        }

        auto [mx, cnt] = st.query(l, r);
        // cout << mx << "," << cnt << " " << r - 1 << endl;
        if(mx == r - 1)
            ans += cnt;
    }
    cout << ans << "\n";
}
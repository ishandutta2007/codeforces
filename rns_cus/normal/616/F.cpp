#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Node {
    map<int, Node *> go;
    int l, r;
    Node *p, *link;

    Node(int _l, int _r, Node *_p): l(_l), r(_r), p(_p), link(0) {}
};

const int MAXN = 100 * 1000 + 5, S = 1000;
string s[MAXN];
int c[MAXN], rr[MAXN], nn, curSuf;
long long ans = 0;
vector<int> a, sid;

Node *splitEdge(Node *v, int pos) {
    Node *res = new Node(v->l, pos, v->p);
    v->p->go[a[v->l]] = res;
    res->go[a[pos]] = v;
    v->p = res;
    v->l = pos;
    return res;
}

pair<Node *, int> go(Node *v, int l, int len) {
    while(len > 0) {
        v = v->go[a[l]];
        len -= v->r - v->l;
        l += v->r - v->l;
    }
    return make_pair(v, v->r + len);
}

void add(int i, pair<Node *, int> &p) {
    Node *w = 0;
    while(curSuf <= i) {
        Node *v = p.first;
        int pos = p.second;
        if(pos != v->r) {
            if(a[i] == a[pos]) {
                p.second++;
                return;
            }
            v = splitEdge(v, pos);
            Node *u = new Node(i, nn, v);
            v->go[a[i]] = u;
            if(w)
                w->link = v;
            w = v;
        }
        else {
            if(w)
                w->link = v;
            w = 0;
            if(v->go.find(a[i]) != v->go.end()) {
                p.first = v->go[a[i]];
                p.second = p.first->l + 1;
                return;
            }
            Node *u = new Node(i, nn, v);
            v->go[a[i]] = u;
        }
        int len = 0, l = v->r;
        Node *q = v;
        while(!q->link && q->p) {
            len += q->r - q->l;
            l -= q->r - q->l;
            q = q->p;
        }
        if(!q->p) {
            if(len)
                p = go(q, l + 1, len - 1);
        }
        else
            p = go(q->link, l, len);
        curSuf++;
    }
}

Node *buildSufTree() {
    nn = a.size();
    Node *root = new Node(0, 0, 0);
    pair<Node *, int> p = make_pair(root, 0);
    curSuf = 0;
    for(int i = 0; i < nn; i++)
        add(i, p);
    return root;
}

long long dfs(Node *v, int dep = 0) {
    long long res = 0;
    if(v->go.empty())
        res += c[sid[nn - dep]];
    for(map<int, Node *>::iterator it = v->go.begin();
        it != v->go.end(); it++)
        res += dfs(it->second, dep + it->second->r - it->second->l);
    if(v->go.empty()) {
        if(a[v->l] < S)
            ans = max(ans, res * (rr[sid[nn - dep]] - (nn - dep)));
    }
    else
        ans = max(ans, res * dep);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++) {
        for(size_t j = 0; j < s[i].length(); j++) {
            a.push_back(s[i][j]);
            sid.push_back(i);
        }
        rr[i] = a.size();
        a.push_back(S + i);
        sid.push_back(i);
    }
    dfs(buildSufTree());
    cout << ans << '\n';
    return 0;
}
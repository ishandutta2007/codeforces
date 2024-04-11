#include <bits/stdc++.h>

#define f first
#define s second

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;
//const li INF = 1e18;
//const int INF = 1e9;

const int INF = 2e9;

struct Node {
    int x, y;
    Node *l, *r;
    int sz, mn;
    bool flag;

    Node(int x): x(x), y(rand()), l(nullptr), r(nullptr), sz(1), mn(x), flag(false) {};
};

int get_sz(Node *now) {
    if (!now)
        return 0;

    return now->sz;
}

int get_min(Node *now) {
    if (!now)
        return INF;

    return now->mn;
}

void update(Node *now) {
    now->sz = 1 + get_sz(now->l) + get_sz(now->r);
    now->mn = min(now->x, min(get_min(now->l), get_min(now->r)));
}

void rev(Node* now, bool f) {
    if (!now)
        return;

    now->flag ^= f;
}

void reverse(Node* now) {
    if (!now->flag)
        return;

    swap(now->l, now->r);
    rev(now->l, now->flag);
    rev(now->r, now->flag);
    now->flag = false;
}

pair<Node*, Node*> split(Node *now, int k) {
    if (!now)
        return {nullptr, nullptr};

    reverse(now);

    if (get_sz(now->l) + 1 <= k) {
        auto ans = split(now->r, k - get_sz(now->l) - 1);
        now->r = ans.first;
        update(now);
        return {now, ans.second};
    } else {
        auto ans = split(now->l, k);
        now->l = ans.second;
        update(now);
        return {ans.first, now};
    }
}

Node* merge(Node *l, Node *r) {
    if (!l)
        return r;

    if (!r)
        return l;

    reverse(l);
    reverse(r);

    if (l->y < r->y) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

Node* push_back(Node* root, int x) {
    Node *now = new Node(x);
    return merge(root, now);
}

pair<int, Node*> get(Node* root, int i) {
    //auto r = split(root, lf);
    //auto r1 = split(r.second, rg - lf);
   // return {get_min(r1.first), merge(merge(r.first, r1.first), r1.second)};

//    auto r = split(root, i);
//    auto r1 = split(r.first, i - 1);
//    return {r1.second->x, merge(merge(r1.first, r1.second), r.second)};

    auto r = split(root, i);
    auto r1 = split(r.second, 1);
    return {r1.first->x, merge(r.first, merge(r1.first, r1.second))};

}

Node* reverse(Node* root, int lf, int rg) {
    auto r = split(root, lf);
    auto r1 = split(r.second, rg - lf);
    r1.first->flag ^= 1;
    return merge(r.first, merge(r1.first, r1.second));
}


void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    Node* root = nullptr;

    for(int i = 0; i < n; i++) {
        root = push_back(root, int(s[i]));
    }

    string t = "";
    for(int i = 0; i < k- 1; i++)
        t += "()";
    for(int i = 0; i <= (n - 2 * k) / 2; i++)
        t+= "(";
    for(int i = 0; i <= (n - 2 * k) / 2; i++)
        t+= ")";

    //cout << t << endl;

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        //cout << i << endl;
        auto p = get(root, i);
        //cout << i << endl;
        root = p.second;
        if(p.f != int(t[i])) {
            int j = i + 1;
            for(; j < n; j++) {
                auto p = get(root, j);
                root = p.second;
                if(p.first == int(t[i])) {
                    break;
                }
            }
            root = reverse(root, i, j + 1);
            ans.push_back({i + 1, j + 1});
        }
    }

    cout << ans.size() << endl;
    for(auto an : ans)
        cout<< an.f << ' ' << an.s << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}
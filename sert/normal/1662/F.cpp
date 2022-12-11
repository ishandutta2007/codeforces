#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(3431);

struct Node {
  int x, y, val;
  Node *l, *r, *mxSum, *mnDif;
  Node(int x, int val): x(x), val(val) {
    l = r = nullptr;
    mxSum = mnDif = this;
    y = static_cast<int>(rnd());
  }
  int getSum() const { return x + val; }
  int getDif() const { return x - val; }
};

Node *recalc(Node *v) {
  if (v == nullptr) return nullptr;
  v->mxSum = v;
  v->mnDif = v;
  if (v->l) {
    if (v->l->mxSum->getSum() > v->mxSum->getSum()) v->mxSum = v->l->mxSum;
    if (v->l->mnDif->getDif() < v->mnDif->getDif()) v->mnDif = v->l->mnDif;
  }
  if (v->r) {
    if (v->r->mxSum->getSum() > v->mxSum->getSum()) v->mxSum = v->r->mxSum;
    if (v->r->mnDif->getDif() < v->mnDif->getDif()) v->mnDif = v->r->mnDif;
  }
  return v;
}

void split(Node *v, int x, Node *&l, Node *&r) {
  if (v == nullptr) { l = r = nullptr; return; }
  if (v->x > x) {
    split(v->l, x, l, v->l);
    r = recalc(v);
  } else {
    split(v->r, x, v->r, r);
    l = recalc(v);
  }
}

Node *merg(Node *v1, Node *v2) {
  if (v1 == nullptr) return v2;
  if (v2 == nullptr) return v1;
  if (v1->y > v2->y) {
    v1->r = merg(v1->r, v2);
    return recalc(v1);
  } else {
    v2->l = merg(v1, v2->l);
    return recalc(v2);
  }
}

Node *del(Node *&root, int x) {
  Node *l, *m, *r;
  split(root, x - 1, l, m);
  split(m, x, m, r);
  root = merg(l, r);
  return m;
}

Node *add(Node *&root, int x, int val) {
  Node *v = new Node(x, val);
  Node *l, *r;
  split(root, x, l, r);
  root = merg(merg(l, v), r);
  return v;
}

int solve() {
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  b--;
  Node *root = nullptr;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (i != a) {
      Node *v = new Node(i, p[i]);
      root = merg(root, v);
    }
  }
  vector<int> dist(n, -1);
  dist[a] = 0;
  queue<int> q;
  q.push(a);

  while (!q.empty() && dist[b] == -1) {
    int v = q.front();
    q.pop();
    //cout << v << " " << dist[v] << endl;

    Node *L, *l, *r, *R;
    split(root, v, l, r);
    split(l, v - p[v] - 1, L, l);
    split(r, v + p[v], r, R);

    auto delFromNode = [&](int pos, Node *&node) {
      dist[pos] = dist[v] + 1;
      q.push(pos);
      del(node, pos);
    };

    while (l && l->mxSum->getSum() >= v) {
      delFromNode(l->mxSum->x, l);
    }

    while (r && r->mnDif->getDif() <= v) {
      delFromNode(r->mnDif->x, r);
    }

    root = merg(merg(L, l), merg(r, R));
  }

  return dist[b];
}

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    //test();
    freopen("../a.in", "r", stdin);
    t = 3;
  }
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
}
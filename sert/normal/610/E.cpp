#include <bits/stdc++.h>
using namespace std;

struct ST {
  vector<char> t;  
  int sz;

  ST(const string &s) {
    sz = s.length();
    t.resize(sz * 4);    
    for (int i = 0; i < sz * 4; i++)
      t[i] = '#';
    build(s);
  }

  void build(const string &s, int v = 0, int l = 0, int r = -1) {
    if (r == -1) r = sz;
    if (l + 1 == r) {
      t[v] = s[l];
      return;
    }
    int m = (l + r) / 2;
    build(s, v * 2 + 1, l, m);
    build(s, v * 2 + 2, m, r);
  }

  void upd(char ch, int L, int R, int v = 0, int l = 0, int r = -1) {
    if (r == -1) r = sz;
    if (L >= r || l >= R) return;
    if (L <= l && r <= R) {
      t[v] = ch;
      return;
    }
    if (t[v] != '#') {
      t[v * 2 + 1] = t[v * 2 + 2] = t[v];
      t[v] = '#';
    }
    int m = (l + r) / 2;
    upd(ch, L, R, v * 2 + 1, l, m);
    upd(ch, L, R, v * 2 + 2, m, r);
  }

  char getChar(int pos, int v = 0, int l = 0, int r = -1) {
    if (r == -1) r = sz;
    if (l + 1 == r) return t[v];
    if (t[v] != '#') {
      t[v * 2 + 1] = t[v * 2 + 2] = t[v];
      t[v] = '#';
    }
    int m = (l + r) / 2;
    if (pos < m) return getChar(pos, v * 2 + 1, l, m);
    else return getChar(pos, v * 2 + 2, m, r);
  }

};

struct Node {
  int x, y, sz;
  Node *left, *right;

  Node(int x) {
    this->x = x;
    this->y = ((rand() << 16) ^ rand());
    left = right = nullptr;
    sz = 1;
  }  
};

int getSize(Node *v) {
  return (v == nullptr ? 0 : v->sz);
}

void upd(Node *v) {
  v->sz = getSize(v->left) + getSize(v->right) + 1;
}

void split(Node *v, int x, Node *&l, Node *&r) {
  if (v == nullptr) {
    l = r = nullptr;
    return;
  }

  if (x <= v->x) {
    split(v->left, x, l, v->left);
    r = v;
  } else {
    split(v->right, x, v->right, r);
    l = v;
  }
  upd(v);
}

Node* merg(Node *v1, Node *v2) {
  if (v1 == nullptr) return v2;
  if (v2 == nullptr) return v1;
  if (v1->y > v2->y) {
    v1->right = merg(v1->right, v2);
    upd(v1);
    return v1;
  } else {
    v2->left = merg(v1, v2->left);
    upd(v2);
    return v2;
  }
}

void insR(Node *&root, int x) {
  root = merg(root, new Node(x));
}

void ins(Node *&root, int x) {
  Node *l = nullptr, *r = nullptr;
  split(root, x, l, r);
  root = merg(merg(l, new Node(x)), r);
}

void remSeg(Node *&root, int L, int R) {  
  if (root == nullptr) return;
  Node *l = nullptr, *m = nullptr, *r = nullptr;
  split(root, L, l, m);
  split(m, R + 1, m, r);
  root = merg(l, r);
}

vector<int> solve(stringstream *ss = nullptr) {
  int n, m, k;
  if (ss == nullptr) cin >> n >> m >> k;
  else (*ss) >> n >> m >> k;
  string s;
  if (ss == nullptr) cin >> s;
  else (*ss) >> s;

  ST st(s);

  // for (int i = 0; i < n * 2 + 5; i++) cout << st.t[i];
  //   cout << "\n";

  vector<int> ansV;

  map<pair<char, char>, Node*> roots;
  for (char c1 = 'a'; c1 <= 'j'; c1++)
    for (char c2 = 'a'; c2 <= 'j'; c2++)      
      roots[make_pair(c1, c2)] = nullptr;

  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) continue;
    Node *&root = roots[make_pair(s[i - 1], s[i])];
    insR(root, i - 1);
  }  

  for (int iq = 0; iq < m; iq++) {
    int t;
    if (ss == nullptr) cin >> t;
    else (*ss) >> t;

    if (t == 2) {
      string alf;
      if (ss == nullptr) cin >> alf;
      else (*ss) >> alf;

      int totDif = 0;
      int totFail = 0;
      for (const auto &it : roots) {        
        totDif += getSize(it.second);
        // if (max(it.first.first,it.first.second) <= 'c')
        // cout << it.first.first << " " << it.first.second << " " << getSize(it.second) << " szdif\n";
      }
      for (int i1 = 0; i1 < k; i1++) {
        for (int i2 = 0; i2 < i1; i2++) {
          totFail += getSize(roots[make_pair(alf[i1], alf[i2])]);
        }
      }      
      // cout << totDif << " " << totFail << " -- ";
      if (ss == nullptr)
        cout << 1 + totFail + (n - 1) - totDif << "\n";
      ansV.push_back(1 + totFail + (n - 1) - totDif);
    } else {
      int l, r;
      char ch;
      if (ss == nullptr) cin >> l >> r >> ch;
      else (*ss) >> l >> r >> ch;
      l--;
      r--;

      for (auto &it : roots) {
        remSeg(it.second, max(0, l - 1), r);
        // if (it.first.first <= 'c' && it.first.second <= 'c')
        //   cout << it.first.first << it.first.second << " " << (int)(it.second == nullptr) << " remSeg\n";
      }

      if (l > 0) {        
        char sch = st.getChar(l - 1);
        // cout << l - 1 << " left char: " << sch << endl;
        if (sch != ch) {
          Node *&root = roots[make_pair(sch, ch)];
          ins(root, l - 1);
        }
      }

      if (r + 1 < n) {
        char sch = st.getChar(r + 1);
        // cout << r + 1 << " right char: " << sch << endl;
        if (sch != ch) {
          Node *&root = roots[make_pair(ch, sch)];
          ins(root, r);
        }
      }

      st.upd(ch, l, r + 1);
    }
  }
  return ansV;
}

vector<int> kek(stringstream &ss) {
  // cout << "in kek" << endl;
  int n, m, k;
  ss >> n >> m >> k;
  string s;
  ss >> s;

  // cout << n << " " << m << " " << k << " " << s << endl;

  vector<int> ansV;
  for (int iq = 0; iq < m; iq++) {
    int t;
    ss >> t;
    if (t == 2) {
      string alf;
      ss >> alf;

      // cout << t << " " << alf << endl;

      vector<int> pos(10);
      for (int i = 0; i < k; i++) pos[alf[i] - 'a'] = i;
      int ans = 1;
      for (int i = 1; i < n; i++) {
        if (pos[s[i - 1] - 'a'] >= pos[s[i] - 'a']) ans++;
      }
      ansV.push_back(ans);
    } else {
      int l, r;
      char ch;
      ss >> l >> r >> ch;

      // cout << t << " " << l << " " << r << " " << ch << endl;

      l--;
      r--;
      for (int i = l; i <= r; i++) s[i] = ch;
    }
  }
  // cout << "out kek" << endl;
  return ansV;
}

ostream& operator<<(ostream &fo, vector<int> v) {
  for (int x : v) fo << x << " ";
  return fo;
}

void test(int test) {
  stringstream s1, s2, s3;

  auto print = [&](string s) {
    s1 << s;
    s2 << s;
    s3 << s;
  };

  print("10 10 3\n");

  string s;
  for (int i = 0; i < 10; i++) s.push_back((char)('a' + rand() % 3));
  print(s + "\n");

  for (int i = 0; i < 10; i++) {
    int t = rand() % 2 + 1;
    if (t == 1) {
      int l = rand() % 10 + 1;
      int r = rand() % 10 + 1;
      if (l > r) swap(l, r);
      char ch = (char)('a' + rand() % 3);
      print("1 " + to_string(l) + " " + to_string(r) + " " + ch + "\n");
    } else {
      string s;
      for (int j = 0; j < 3; j++) s.push_back((char)('a' + j));
      random_shuffle(s.begin(), s.end());
      print("2 " + s + "\n");
    }
  }
  
  // while (getline(s3, s)) {
  //   cout << s << "\n";
  // }
  // exit(0);

  auto a1 = solve(&s1);
  auto a2 = kek(s2);

  if (a1 != a2) {
    cout << "test: " << test << "\n";
    string s;
    while (getline(s3, s)) {
      cout << s << "\n";
    }

    cout << "sol: " << a1 << "\n";
    cout << "kek: " << a2 << "\n";
    exit(0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;

  for (int i = 0; i < 10000; i++) {
    test(i);
  }
}
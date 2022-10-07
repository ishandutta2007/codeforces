#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define hash hhh
#define pow pw
#define repi(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
typedef long long ll;

const int MAXN = 100100;
ll HASH_BASE = 37;
ll pows[MAXN];
ll hsh[MAXN];
int QK[MAXN];
string QS[MAXN];

int QA[MAXN]; // ans

string s;
map<int, vector<int> > qm;


void prec() {
  pows[0] = 1;
  for(int i = 0; i + 1 < MAXN; ++i) {
    pows[i + 1] = pows[i] * HASH_BASE;
  }

  for(int i = 0; i < s.size(); ++i) {
    hsh[i + 1] = hsh[i] * HASH_BASE + s[i];
  }
}

unordered_map<ll, vector<int> > occ;
void process(int l) {
  for(int i = 0; i + l <= s.size(); ++i) {
    ll h = hsh[i + l] - hsh[i] * pows[l];
    if (occ.find(h) != occ.end()) {
      occ[h].push_back(i);
    }
  }
}

ll hash(string &t) {
  ll h = 0;
  for(int i = 0; i < t.size(); ++i) {
    h = h * HASH_BASE + t[i];
  }
  return h;
}

int q;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  prec();
  cin >> q;
  for(int i = 0; i < q; ++i) {
    cin >> QK[i] >> QS[i];
    qm[QS[i].size()].push_back(i);
  }

  repi(i, qm) {
    int l = i->first;
    vector<int> &qv = i->second;


    occ.clear();
    repi(j, qv) {
      int q = *j;
      ll h = hash(QS[q]);
      occ[h] = vector<int>();
    }
    process(l);

    repi(j, qv) {
      int q = *j;
      ll h = hash(QS[q]);
      vector<int> &o = occ[h];
      int &ans = QA[q];
      ans = MAXN;
      for(int k = 0; k + QK[q] <= o.size(); ++k) {
        int diff = o[k + QK[q] - 1] - o[k];
        ans = min(ans, diff + l);
      }
      if (ans == MAXN) ans = -1;
    }
  }

  for(int i = 0; i < q; ++i) {
    cout << QA[i] << "\n";
  }
}
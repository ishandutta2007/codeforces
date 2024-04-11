#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partA[8];
int partB[8];

int par[8]; // par[e] = id of node that is progenitor of ethnicity e, 0 if not reachable

const int MAXN = 300;
int CD[MAXN];
int CT[MAXN];
int T[MAXN]; // T[i]: whether testing is on for node i

typedef pair<int, int> pii;
vector<pii> edges;

int n;

bool make(int eth) {
  if (par[eth]) return true;
  for(int i = 1; i <= n; ++i) {
    if (CD[i] == eth) {
      if (!par[partA[eth]]) return false;
      if (!par[partB[eth]]) return false;
      edges.push_back(pii(par[partA[eth]], i));
      edges.push_back(pii(par[partB[eth]], i));
      par[eth] = i; // i will be progenitor
      T[i] = 0;
      break;
    }
  }
  return true;
}

void visit(int eth) {
  for(int i = 1; i <= n; ++i) {
    if (CD[i] == eth) {
      if (!par[CT[i]]) {
        par[CT[i]] = i;
      }
    }
  }
}

int main() {
  partA[3] = 1;
  partB[3] = 2;
  partA[5] = 1;
  partB[5] = 4;
  partA[6] = 2;
  partB[6] = 4;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    CD[i] = a * 4 + b * 2 + c;
    T[i] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    CT[i] = a * 4 + b * 2 + c;
    CT[i] &= CD[i];
  }

  par[7] = 1; // 1 is all-father; progenitor of white ethnicity (111)
  for(int i = 7; i >= 1; --i) {
    if (par[i]) {
      visit(i);
    }
  }

  bool ok = true;
  ok &= make(3);
  ok &= make(5);
  ok &= make(6);
  for (int i = 1; i <= n; ++i) {
    if (par[CD[i]] == i) continue;
    if (!par[CD[i]]) ok = false;
    edges.push_back(pii(par[CD[i]], i));
  }
  if (!ok) {
    cout << "Impossible\n";
  } else {
    cout << "Possible\n";
    for (int i = 1; i <= n; ++i) {
      cout << T[i] << " ";
    }
    cout << "\n";
    cout << edges.size() << "\n";
    for (pii p: edges) {
      cout << p.first << " " << p.second << "\n";
    }
  }
}
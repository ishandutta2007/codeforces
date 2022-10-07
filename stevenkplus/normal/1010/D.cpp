//flip[1] = true;
//flip[x][0] = true iff ... AND 0 1, OR 1 0, XOR



#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001000;
int conn[MAXN][2];
int val[MAXN];
int flip[MAXN];
char type[MAXN];

#define A conn[cur][0]
#define B conn[cur][1]
void dfs1(int cur) {
  if (!A) return;
  dfs1(A);
  if (type[cur] != 'N') dfs1(B);
  if (type[cur] == 'X') {
    val[cur] = val[A] ^ val[B];
  } else if (type[cur] == 'A') {
    val[cur] = val[A] & val[B];
  } else if (type[cur] == 'N') {
    val[cur] = 1 - val[A];
  } else if (type[cur] == 'O') {
    val[cur] = val[A] | val[B];
  }
}

void dfs2(int cur) {
  flip[cur] = 1;
  if (type[cur] == 'X') {
    dfs2(A);
    dfs2(B);
  } else if (type[cur] == 'A') {
    if (val[A] == 1) {
      dfs2(B);
    }
    if (val[B] == 1) {
      dfs2(A);
    }
  } else if (type[cur] == 'O') {
    if (val[A] == 0) {
      dfs2(B);
    }
    if (val[B] == 0) {
      dfs2(A);
    }
  } else if (type[cur] == 'N') {
    dfs2(A);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    type[i] = s[0];
    if (type[i] == 'I') {
      cin >> val[i];
    } else if (type[i] == 'N') {
      cin >> conn[i][0];
    } else {
      cin >> conn[i][0] >> conn[i][1];
    }
  }

  dfs1(1);

  dfs2(1);

  for(int i = 1; i <= n; ++i) {
    if (conn[i][0]) continue;
    cout << (flip[i] ^ val[1]);
  }
  cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// a ^ b mod c
ll pw(int a, int b, int c) {
  if (b == 0) return 1;
  ll r = pw(a, b / 2, c);
  r = r * r % c;
  if (b & 1) r = r * a % c;
  return r;
}

int inv(int x, int p) {
  return pw(x, p - 2, p);
}

int inc(int x, int p) {
  return (x + 1) % p;
}

int dec(int x, int p) {
  return (x + p - 1) % p;
}

int dist(int a, int b, int p) {
  a = (a + p - b) % p;
  if (a < p / 2) return a;
  else return p - a;
}

int perm[20];
int tt[3][2] = {
  {0, 2},
  {1, 2},
  {0, 1}
};

int opp[3] = { 1, 0, 2 };

const int MAXN = 11000000;
int getbucket(int i, int p) {
  // if (i + 100 > p) {
    // if (i + 50 > p) {
      // return 0;
    // } else {
      // return i / 100 - 1;
    // }
  // } else {
    return i / 100;
  // }
}

int bucket[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // pls dont hack me
  srand('1'+'1'+'l'+'L'+'0'+0+'O'+'o'+'1'+'o'+1+'0'+10+'0' + 1);
  int u, v, p;
  cin >> u >> v >> p;

  int perm = rand();
  // lol, this is 3 ^ 17
  for(int i = 0; i < (1 << 19); ++i) {
    int cur = u;
    int pmove = 0;
    for(int j = 0; j < 19; ++j) {
      int bit = ((i ^ perm) >> j) & 1;
      int move = tt[pmove][bit];
      pmove = move;
      if (move == 0) {
        cur = inc(cur, p);
      } else if (move == 1) {
        cur = dec(cur, p);
      } else {
        cur = inv(cur, p);
      }
      bucket[getbucket(cur, p)] = i;
    }
  }

  int ansi = -1, ansc, ansj;
  for(int i = 0; i < (1 << 24); ++i) {
    int cur = v;
    int pmove = 0;
    for(int j = 0; j < 24; ++j) {
      int bit = ((i ^ perm) >> j) & 1;
      int move = tt[pmove][bit];
      pmove = move;
      if (move == 0) {
        cur = inc(cur, p);
      } else if (move == 1) {
        cur = dec(cur, p);
      } else {
        cur = inv(cur, p);
      }
      if (bucket[getbucket(cur, p)]) {
        ansc = cur;
        ansi = i;
        ansj = j;
        break;
      }
    }
    if (ansi != -1) break;
  }

  vector<int> out;
  if (ansi != -1) {
    int cur = u;
    int pmove = 0;
    for(int j = 0; j < 19; ++j) {
      int bit = ((bucket[getbucket(ansc, p)] ^ perm) >> j) & 1;
      int move = tt[pmove][bit];
      pmove = move;
      out.push_back(move + 1);
      if (move == 0) {
        cur = inc(cur, p);
      } else if (move == 1) {
        cur = dec(cur, p);
      } else {
        cur = inv(cur, p);
      }
      if (getbucket(cur, p) == getbucket(ansc, p)) {
        int d = dist(cur, ansc, p);
        int dir = ((cur + d) % p == ansc) ? 1 : 2;
        for(int i = 0; i < d; ++i) {
          out.push_back(dir);
        }

        pmove = 0;
        vector<int> moves;
        for(int k = 0; k <= ansj; ++k) {
          int bit = ((ansi ^ perm) >> k) & 1;
          int move = tt[pmove][bit];
          pmove = move;
          moves.push_back(move);
        }
        reverse(moves.begin(), moves.end());
        for(int move: moves) {
          out.push_back(opp[move] + 1);
        }
        break;
      }
    }
  } else {
    while (true);
}
  printf("%d\n", out.size());
  for (int i: out) {
    printf("%d ", i);
  }
  printf("\n");
}
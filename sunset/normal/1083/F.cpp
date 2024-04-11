#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 14;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> c(n + 1);
  for (int i = 0; i <= n; ++i) {
    if (i < n) {
      c[i] = a[i] ^ b[i];
    }
    if (i) {
      c[i] ^= a[i - 1] ^ b[i - 1];
    }
  }
  vector<vector<int>> group(m);
  for (int i = 0; i <= n; ++i) {
    group[i % m].push_back(i);
  }
  vector<int> seq;
  vector<int> pos(n + 1);
  int zeros = 0;
  vector<int> endpos(m);
  for (int i = 0; i < m; ++i) {
    int sum = 0;
    for (auto x : group[i]) {
      sum ^= c[x];
      seq.push_back(sum);
      pos[x] = seq.size() - 1;
    }
    if (!sum) {
      ++zeros;
    }
    endpos[i] = seq.size();
  }
  int block = sqrt(n + 1), nblock = n / block + 1;
  vector<vector<int>> cnt(nblock, vector<int> (MAX));
  vector<int> tag(nblock);
  for (int i = 0; i <= n; ++i) {
    ++cnt[i / block][seq[i]];
  }
  if (zeros == m) {
    int answer = 0;
    for (int i = 0; i < nblock; ++i) {
      answer += cnt[i][tag[i]];
    }
    printf("%d\n", n + 1 - answer);
  } else {
    puts("-1");
  }
  auto modify = [&](int p, int value) {
    int l = pos[p], r = endpos[p % m] - 1;
    int bl = l / block, br = r / block;
    if (seq[r] == tag[br]) {
      --zeros;
    }
    if (bl == br) {
      for (int i = l; i <= r; ++i) {
        --cnt[bl][seq[i]];
        seq[i] ^= value;
        ++cnt[bl][seq[i]];
      }
    } else {
      for (int i = l; i < (bl + 1) * block; ++i) {
        --cnt[bl][seq[i]];
        seq[i] ^= value;
        ++cnt[bl][seq[i]];
      }
      for (int i = bl + 1; i < br; ++i) {
        tag[i] ^= value;
      }
      for (int i = br * block; i <= r; ++i) {
        --cnt[br][seq[i]];
        seq[i] ^= value;
        ++cnt[br][seq[i]];
      }
    }
    if (seq[r] == tag[br]) {
      ++zeros;
    }
  };
  while (q--) {
    string type;
    int pos, value, delta;
    cin >> type >> pos >> value;
    --pos;
    if (type == "a") {
      delta = a[pos] ^ value;
      a[pos] = value;
    } else {
      delta = b[pos] ^ value;
      b[pos] = value;
    }
    modify(pos, delta);
    modify(pos + 1, delta);
    if (zeros == m) {
      int answer = 0;
      for (int i = 0; i < nblock; ++i) {
        answer += cnt[i][tag[i]];
      }
      printf("%d\n", n + 1 - answer);
    } else {
      puts("-1");
    }
  }
  return 0;
}
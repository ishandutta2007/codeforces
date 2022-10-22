#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}



int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  string s;
  cin >> s;

  int n = s.size();

  vector <pair <int, int>> blocks;
  int tp = 0;
  int len = 0;

  for (int i = 0; i < n; ++i) {
    int nxt = (s[i] == '#' ? 1 : 0);
    if (tp != nxt) {
      if (tp) {
        blocks.pb({len, i - 1});
      }
      tp = nxt;
      len = 1;
    } else {
      ++len;
    }
  }
  if (tp) {
    blocks.pb({len, n - 1});
  }

  /*for (auto t : blocks) {
    cout << t.x << " " << t.y << "\n";
  }*/

  if (!blocks.size()) {
    cout << "0\n";
    return 0;
  }

  for (int S = 1; S <= n; ++S) {
    bool can = true;
    int val = blocks.size() * (ll) (n - S + 1) + (blocks.size() - 1);
    if (val > n) {
      continue;
    }
    for (int i = 0; i < (int) blocks.size(); ++i) {
      int len = blocks[i].x;
      int pos = blocks[i].y;
      len += (n - S);
      int was = (i ? blocks[i - 1].y : -2);
      int rem = pos - was - 1 - len;

      //cout << S << " " << pos << " " << len << " " << was << " " << rem << endl;
      
      if (rem < 0 || rem == 1) {
        can = false;
        break;
      }
      if (rem % 2 && S == 1) {
        can = false;
        break;
      }
      if (i == (int) blocks.size() - 1) {
        int nxt = n - pos - 1 - (n - S);
        if (nxt < 0 || nxt == 1) {
          can = false;
          break;
        }
        if (nxt % 2 && S == 1) {
          can = false;
          break;
        }
      }
    }
    if (!can) {
      continue;
    }
    vector <int> res;
    for (int i = 0; i < (int) blocks.size(); ++i) {
      int len = blocks[i].x;
      int pos = blocks[i].y;
      len += (n - S);
      int was = (i ? blocks[i - 1].y : -2);
      int rem = pos - was - 1 - len;
      
      if (rem < 0 || rem == 1) {
        assert(false);
      }
      if (rem % 2 && S == 1) {
        assert(false);
      }
      if (rem % 2) {
        res.pb(2);
        rem -= 3;
      }
      while (rem) {
        res.pb(1);
        rem -= 2;
      }
      res.pb(len);
      if (i == (int) blocks.size() - 1) {
        int rem = n - pos - 1 - (n - S);
        //cout << S << " " << rem << endl;
        if (rem < 0 || rem == 1) {
          assert(false);
        }
        if (rem % 2 && S == 1) {
          assert(false);
        }
        if (rem % 2) {
          res.pb(2);
          rem -= 3;
        }
        while (rem) {
          res.pb(1);
          rem -= 2;
        }
      }
    }
    cout << res.size() << "\n";
    for (int x : res) {
      cout << x << " ";
    }
    cout << "\n";
    return 0;
  }

  cout << "-1\n";
}
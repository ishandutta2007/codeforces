#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
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

void sort(vector<int>& a, vector<int> &pos) {
  int cnt = 0;
  for (int x : pos) {
    cnt += !a[x];
  }
  for (int i = 0; i < pos.size(); ++i) {
    if (i < cnt) {
      a[pos[i]] = 0;
    } else {
      a[pos[i]] = 1;
    }
  }
}

const int SZ = 24;
struct HashTable{
    ll was[(1 << SZ) + 7];
    int val[(1 << SZ) + 7];

    HashTable() { for (int i = 0; i < (1 << SZ) + 7; i++) was[i] = -1; }

    void clear(){
        for (int i = 0; i < (1 << SZ) + 7; i++) was[i] = -1;
    }

    void set(ll pos, int new_val){
        int gg = ((1 << SZ) - 1) & pos;
        int p = (gg * (ll)gg * 3 + gg * 7 + 11) & ((1 << SZ) - 1);
        while(1){
            if (was[p] == -1){
                was[p] = pos;
                val[p] = new_val;
                return;
            } else if (was[p] == pos) {
                val[p] = new_val;
                return;
            }
            p++;
            if (p == (1 << SZ)) p = 0;
        }
    }

    int get(ll pos){
        int gg = ((1 << SZ) - 1) & pos;
        int p = (gg * (ll)gg * 3 + gg * 7 + 11) & ((1 << SZ) - 1);
        while(1){
            if (was[p] == -1){
                return 0;
            } else if (was[p] == pos) {
                return val[p];
            }
            p++;
            if (p == (1 << SZ)) p = 0;
        }
    }
};


const int K = 11;
const int N = 41;

HashTable used;

ll masks[K];
ll totals[K];
ll pmasks[K][N];
int nbits[K];

int n, k;

void rec(ll mask, int now) {
	if (now == k) {
		for (int i = 0; i + 1 < n; ++i) {
			if (mask & (1LL << i) && !(mask & (1LL << (i + 1)))) {
				cout << "REJECTED\n";
				exit(0);
			}
		}
		return;
	}
	/*if (used.get((mask << 3) + now)) {
		return;
	}
	used.set((mask << 3) + now, 1);*/

	int cnt = __builtin_popcountll(mask & masks[now + 1]);
	int total = __builtin_popcountll(masks[now + 1]);
	ll wmask = mask & ~masks[now + 1];
	int nbit = nbits[now + 1];
	//cout << now << " " << bitset<4>(mask) << " " << cnt << " " << total << " " << bitset<4>(wmask) << " " << nbit << endl;

	for (int i = cnt + nbit; i >= cnt; --i) {
		rec(wmask | pmasks[now + 1][i], now + 1);
	}
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;

  if (n == 1) {
    cout << "ACCEPTED\n";
    return 0;
  }

  ll total = 0;

  vector <vector<int>> ops(k);
  for (int i = 0; i < k; ++i) {
    int q;
    cin >> q;
    vector<int> now(q);
    for (int j = 0; j < q; ++j) {
      cin >> now[j];
      --now[j];
      masks[i + 1] |= (1LL << now[j]);
    }
    total |= masks[i + 1];
    ops[i] = now;
  	totals[i + 1] = total;
  	nbits[i + 1] = __builtin_popcountll(totals[i] | masks[i + 1]) - __builtin_popcountll(totals[i]);
  	
  	ll dmask = masks[i + 1];
 	while (dmask) {
 		pmasks[i + 1][__builtin_popcountll(dmask)] = dmask;
 		dmask = dmask & (dmask - 1);
 	}
  }

  if (total != (1LL << n) - 1) {
    cout << "REJECTED\n";
    return 0;
  }

  rec(0, 0);
  cout << "ACCEPTED\n";
}
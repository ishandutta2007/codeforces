#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		BIT = vector<T>(N + 1, 0);
	}
	void add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans;
	}
	T query(int L, int R){
		return sum(R) - sum(L);
	}
	T all(){
		return BIT[0];
	}
};
struct kth_set{
  int N;
  vector<int> BIT;
  kth_set(int N): N(N){
    BIT = vector<int>(N + 1, 0);
  }
  void insert(int x){
    x++;
    while (x <= N){
      BIT[x]++;
      x += x & -x;
    }
  }
  int find(int k){
    int tv = N + 1;
    int fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int sum = 0;
      int x = mid;
      while (x > 0){
        sum += BIT[x];
        x -= x & -x;
      }
      if (sum >= k){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    return fv;
  }
};
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    if (a[i] > i + 1){
      b[i] = -1;
    } else {
      b[i] = i + 1 - a[i];
    }
  }
  /*
  cout << "b: ";
  for (int i = 0; i < n; i++){
    cout << b[i] << ' ';
  }
  cout << endl;
  */
  vector<int> c(n, 0);
  if (b[0] != -1){
    c[0]++;
  }
  for (int i = 1; i < n; i++){
    if (b[i] == -1){
      c[i] = c[i - 1];
    } else if (c[i - 1] < b[i]){
      c[i] = c[i - 1];
      b[i] = -1;
    } else {
      c[i] = c[i - 1] + 1;
    }
  }
  /*
  cout << "b: ";
  for (int i = 0; i < n; i++){
    cout << b[i] << ' ';
  }
  cout << endl;
  cout << "c: ";
  for (int i = 0; i < n; i++){
    cout << c[i] << ' ';
  }
  cout << endl;
  */
  vector<int> d(n, -1);
  for (int i = 0; i < n; i++){
    if (b[i] != -1){
      d[i] = c[i] - b[i];
    }
  }
  /*
  cout << "d: ";
  for (int i = 0; i < n; i++){
    cout << d[i] << ' ';
  }
  cout << endl;
  */
  kth_set st(n);
  vector<int> t(n, -1);
  for (int i = 0; i < n; i++){
    if (b[i] != -1){
      if (b[i] == 0){
        t[i] = i;
      } else {
        t[i] = st.find(d[i]);
      }
      st.insert(t[i]);
    }
  }
  /*
  cout << "t: ";
  for (int i = 0; i < n; i++){
    cout << t[i] << ' ';
  }
  cout << endl;
  */
  vector<vector<pair<int, int>>> query(n);
  for (int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    query[x].push_back(make_pair(y, i));
  }
  vector<vector<int>> op(n);
  for (int i = 0; i < n; i++){
    if (t[i] != -1){
      op[t[i]].push_back(i);
    }
  }
  binary_indexed_tree<int> BIT(n);
  for (int i = 0; i < n; i++){
    if (b[i] != -1){
      BIT.add(i, 1);
    }
  }
  vector<int> ans(q, -1);
  for (int i = 0; i < n; i++){
    for (auto P : query[i]){
      int y = P.first;
      int id = P.second;
      int r = n - y;
      ans[id] = BIT.query(0, r);
    }
    for (int x : op[i]){
      BIT.add(x, -1);
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << endl;
  }
}
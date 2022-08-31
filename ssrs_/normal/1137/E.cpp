#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	dual_segment_tree(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans += ST[k];
		}
		return ans;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] += x;
			return;
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	void all_add(T x){
		ST[0] += x;
	}
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<tuple<int, long long, long long>> query(m);
  vector<long long> pos = {0};
  long long cl = 0, cr = n;
  for (int i = 0; i < m; i++){
    int t;
    cin >> t;
    if (t == 1){
      int k;
      cin >> k;
      query[i] = make_tuple(t, k, 0);
      cl -= k;
      pos.push_back(cl);
    }
    if (t == 2){
      int k;
      cin >> k;
      query[i] = make_tuple(t, k, 0);
      pos.push_back(cr);
      cr += k;
    }
    if (t == 3){
      long long b, s;
      cin >> b >> s;
      b -= cl * s;
      query[i] = make_tuple(t, b, s);
    }
  }
  sort(pos.begin(), pos.end());
  int cnt = pos.size();
  int L = lower_bound(pos.begin(), pos.end(), 0) - pos.begin();
  int R = L + 1;
  dual_segment_tree<long long> A(cnt), B(cnt);
  stack<int> st;
  st.push(L);
  for (int i = 0; i < m; i++){
    int t = get<0>(query[i]);
    if (t == 1){
      L--;
      while (!st.empty()){
        st.pop();
      }
      st.push(L);
    }
    if (t == 2){
      st.push(R);
      R++;
    }
    if (t == 3){
      long long b = get<1>(query[i]);
      long long s = get<2>(query[i]);
      A.range_add(L, R, s);
      B.range_add(L, R, b);
    }
    while (st.size() >= 2){
      int p2 = st.top();
      st.pop();
      int p1 = st.top();
      long long A1 = A[p1] * pos[p1] + B[p1];
      long long A2 = A[p2] * pos[p2] + B[p2];
      if (A1 > A2){
        st.push(p2);
        break;
      }
    }
    while (st.size() >= 3){
      int p3 = st.top();
      st.pop();
      int p2 = st.top();
      st.pop();
      int p1 = st.top();
      long long A1 = A[p1] * pos[p1] + B[p1];
      long long A2 = A[p2] * pos[p2] + B[p2];
      long long A3 = A[p3] * pos[p3] + B[p3];
      if ((A1 - A2) * (pos[p3] - pos[p2]) > (A2 - A3) * (pos[p2] - pos[p1])){
        st.push(p2);
        st.push(p3);
        break;
      } else {
        st.push(p3);
      }
    }
    int id = st.top();
    cout << pos[id] - pos[L] + 1 << ' ' << A[id] * pos[id] + B[id] << endl;
  }
}
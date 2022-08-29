#include <bits/stdc++.h>
using namespace std;
long long inversion_number(vector<int> A){
	int N = A.size();
	vector<int> B = A;
	sort(B.begin(), B.end());
	map<int, int> mp;
	for (int i = 0; i < N; i++){
		mp[B[i]] = i + 1;
	}
	for (int i = 0; i < N; i++){
		A[i] = mp[A[i]];
	}
	long long ans = 0;
	vector<int> BIT(N + 1, 0);
	for (int i = 0; i < N; i++){
		ans += i;
		int j = A[i];
		while (j > 0){
			ans -= BIT[j];
			j -= j & -j;
		}
		j = A[i];
		while (j <= N){
			BIT[j]++;
			j += j & -j;
		}
	}
	return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    set<int> st;
    for (int j = 0; j < n; j++){
      st.insert(a[j]);
    }
    long long I = inversion_number(a);
    if (st.size() == n && I % 2 == 1){
      cout << -1 << endl;
    } else {
      vector<pair<int, int>> b(n);
      for (int j = 0; j < n; j++){
        b[j] = make_pair(a[j], j);
      }
      sort(b.begin(), b.end());
      map<pair<int, int>, int> mp;
      for (int j = 0; j < n; j++){
        mp[b[j]] = j;
      }
      vector<int> c(n);
      for (int j = 0; j < n; j++){
        c[j] = mp[make_pair(a[j], j)];
      }
      if (inversion_number(c) % 2 == 1){
        map<int, int> cnt;
        int same;
        for (int j = 0; j < n; j++){
          cnt[a[j]]++;
          if (cnt[a[j]] >= 2){
            same = a[j];
          }
        }
        int pos1 = -1;
        int pos2 = -1;
        for (int j = 0; j < n; j++){
          if (a[j] == same){
            if (pos1 == -1){
              pos1 = j;
            } else {
              pos2 = j;
            }
          }
        }
        swap(c[pos1], c[pos2]);
      }
      /*
      for (int j = 0; j < n; j++){
        cout << c[j] << ' ';
      }
      cout << endl;
      */
      vector<int> pos(n);
      for (int j = 0; j < n; j++){
        pos[c[j]] = j;
      }
      vector<int> op;
      for (int j = 0; j < n; j++){
        while (pos[j] - 2 >= j){
          int s = pos[j] - 2;
          op.push_back(s);
          int e1 = c[s];
          int e2 = c[s + 1];
          int e3 = c[s + 2];
          pos[e1] = s + 1;
          pos[e2] = s + 2;
          pos[e3] = s;
          c[s] = e3;
          c[s + 1] = e1;
          c[s + 2] = e2;
          /*
          for (int k = 0; k < n; k++){
            cout << c[k] << ' ';
          }
          cout << endl;
          */
        }
        if (pos[j] == j + 1){
          int s = pos[j] - 1;
          op.push_back(s);
          op.push_back(s);
          int e1 = c[s];
          int e2 = c[s + 1];
          int e3 = c[s + 2];
          pos[e1] = s + 2;
          pos[e2] = s;
          pos[e3] = s + 1;
          c[s] = e2;
          c[s + 1] = e3;
          c[s + 2] = e1;
        }
      }
      int op_cnt = op.size();
      cout << op_cnt << endl;
      for (int j = 0; j < op_cnt; j++){
        cout << op[j] + 1;
        if (j < op_cnt - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}
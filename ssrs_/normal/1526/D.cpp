#include <bits/stdc++.h>
using namespace std;
vector<char> C = {'A', 'N', 'O', 'T'};
template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
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
	T sum(int L, int R){
		return sum(R) - sum(L);
	}
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string a;
    cin >> a;
    int N = a.size();
    vector<int> id(N, 0);
    vector<int> cnt(4, 0);
    for (int j = 0; j < N; j++){
      for (int k = 0; k < 4; k++){
        if (a[j] == C[k]){
          id[j] = k;
          cnt[k]++;
        }
      }
    }
    string b = "";
    long long mx = -1;
    vector<int> p = {0, 1, 2, 3};
    while (true){
      vector<int> id2;
      for (int j = 0; j < 4; j++){
        for (int k = 0; k < cnt[p[j]]; k++){
          id2.push_back(p[j]);
        }
      }
      vector<queue<int>> Q(4);
      for (int j = 0; j < N; j++){
        Q[id[j]].push(j);
      }
      vector<int> p2;
      for (int j = 0; j < N; j++){
        p2.push_back(Q[id2[j]].front());
        Q[id2[j]].pop();
      }
      long long x = 0;
      binary_indexed_tree<int> BIT(N);
      for (int j = 0; j < N; j++){
        x += BIT.sum(p2[j], N);
        BIT.add(p2[j], 1);
      }
      if (x > mx){
        mx = x;
        string b2;
        for (int j = 0; j < 4; j++){
          b2 += string(cnt[p[j]], C[p[j]]);
        }
        b = b2;
      }
      if (!next_permutation(p.begin(), p.end())){
        break;
      }
    }
    cout << b << "\n";
  }
}
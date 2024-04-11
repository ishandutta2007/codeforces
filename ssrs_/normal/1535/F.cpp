#include <bits/stdc++.h>
using namespace std;
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
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  int m = s[0].size();
  map<array<int, 26>, vector<int>> mp;
  for (int i = 0; i < n; i++){
    array<int, 26> cnt;
    for (int j = 0; j < 26; j++){
      cnt[j] = 0;
    }
    for (int j = 0; j < m; j++){
      cnt[s[i][j] - 'a']++;
    }
    mp[cnt].push_back(i);
  }
  long long ans = 0;
  int cnt = 0;
  for (auto P : mp){
    int n2 = P.second.size();
    vector<string> s2(n2);
    for (int i = 0; i < n2; i++){
      s2[i] = s[P.second[i]];
    }
    ans += (long long) cnt * n2 * 1337;
    ans += (long long) n2 * (n2 - 1);
    sort(s2.begin(), s2.end());
    vector<pair<string, int>> P2(n2);
    for (int i = 0; i < n2; i++){
      P2[i] = make_pair(s2[i], i);
      reverse(P2[i].first.begin(), P2[i].first.end());
    }
    sort(P2.begin(), P2.end());
    vector<string> s3(n2);
    for (int i = 0; i < n2; i++){
      s3[i] = P2[i].first;
    }
    vector<int> spos(n2);
    for (int i = 0; i < n2; i++){
      spos[P2[i].second] = i;
    }
    vector<vector<int>> prel(m + 1, vector<int>(n2, -1));
    vector<vector<int>> prer(m + 1, vector<int>(n2, -1));
    for (int i = 0; i < n2; i++){
      prel[0][i] = 0;
      prer[0][i] = n2;
    }
    for (int i = 1; i <= m; i++){
      for (int j = 0; j < n2; j++){
        if (prel[i][j] == -1){
          int t = j;
          while (true){
            t++;
            if (t == prer[i - 1][j]){
              break;
            }
            if (s2[j][i - 1] != s2[t][i - 1]){
              break;
            }
          }
          for (int k = j; k < t; k++){
            prel[i][k] = j;
            prer[i][k] = t;
          }
        }
      }
    }
    vector<vector<int>> sufl(m + 1, vector<int>(n2, -1));
    vector<vector<int>> sufr(m + 1, vector<int>(n2, -1));
    for (int i = 0; i < n2; i++){
      sufl[0][i] = 0;
      sufr[0][i] = n2;
    }
    for (int i = 1; i <= m; i++){
      for (int j = 0; j < n2; j++){
        if (sufl[i][j] == -1){
          int t = j;
          while (true){
            t++;
            if (t == sufr[i - 1][j]){
              break;
            }
            if (s3[j][i - 1] != s3[t][i - 1]){
              break;
            }
          }
          for (int k = j; k < t; k++){
            sufl[i][k] = j;
            sufr[i][k] = t;
          }
        }
      }
    }
    vector<vector<pair<int, int>>> query_add(n2 + 1);
    vector<vector<pair<int, int>>> query_sub(n2 + 1);
    for (int i = 0; i < n2; i++){
      vector<int> w;
      w.push_back(0);
      for (int j = 0; j < m - 1; j++){
        if (s2[i][j] > s2[i][j + 1]){
          w.push_back(j + 1);
        }
      }
      w.push_back(m);
      int k = w.size();
      for (int j = 0; j < k - 1; j++){
        int L = w[j];
        int R = m - w[j + 1];
        query_sub[sufl[R][spos[i]]].push_back(make_pair(prel[L][i], prer[L][i]));
        query_add[sufr[R][spos[i]]].push_back(make_pair(prel[L][i], prer[L][i]));
        ans++;
      }
    }
    binary_indexed_tree<int> BIT(n2);
    for (int i = 0; i <= n2; i++){
      int cnt1 = query_add[i].size();
      for (int j = 0; j < cnt1; j++){
        int l = query_add[i][j].first;
        int r = query_add[i][j].second;
        ans -= BIT.sum(l, r);
      }
      int cnt2 = query_sub[i].size();
      for (int j = 0; j < cnt2; j++){
        int l = query_sub[i][j].first;
        int r = query_sub[i][j].second;
        ans += BIT.sum(l, r);
      }
      if (i < n2){
        BIT.add(P2[i].second, 1);
      }
    }
    cnt += n2;
  }
  cout << ans << endl;
}
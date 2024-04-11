#include <bits/stdc++.h>
using namespace std;
long long inversion_number(vector<int> &p){
	int N = p.size();
	long long ans = 0;
	vector<int> bit(N + 1, 0);
	for (int i = 0; i < N; i++){
		ans += i;
		int j = p[i] + 1;
		while (j > 0){
			ans -= bit[j];
			j -= j & -j;
		}
		j = p[i] + 1;
		while (j <= N){
			bit[j]++;
			j += j & -j;
		}
	}
 	return ans;
}
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<queue<int>> id(26);
  for (int i = 0; i < n; i++){
    id[s[i] - 'a'].push(i);
  }
  reverse(s.begin(), s.end());
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    p[i] = id[s[i] - 'a'].front();
    id[s[i] - 'a'].pop();
  }
  cout << inversion_number(p) << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GGC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
using namespace std;
//#define int long long


signed main(){
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vector<int>a(m);
	vector<int>b(s);
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	for(int i = 0; i < s; i++){
		cin >> b[i];
	}
	int x = m - k * n;
	map<int, int>mp;
	int c = 1;
	vector<int>colvo(k + 1);
	for(int i = 0; i < s; i++){
		if(mp[b[i]] == 0){
			mp[b[i]] = c;
			c++;
		}
		colvo[mp[b[i]] - 1]++;
	}
	c--;
	vector<vector<int>>pref1(m / k + 1, vector<int>(c));
	vector<vector<int>>pref2(m / k + 1, vector<int>(c));
	vector<int>now(c);
	for(int i = 0; i < m / k; i++){
		for(int j = 0; j < k; j++){
			if(mp[a[i * k + j]] != 0){
				pref1[i][mp[a[i * k + j]] - 1]++;
			}
		}
		for(int j = 0; j < c; j++){
			pref1[i + 1][j] = pref1[i][j];
		}
	}
	for(int q = 0; q < x + k; q++){
		if(mp[a[q]] != 0){
			pref2[0][mp[a[q]] - 1]++;
		}
		for(int j = 0; j < c; j++){
			pref2[1][j] = pref2[0][j];
		}
	}
	for(int i = 1; i < (m - x) / k; i++){
		for(int j = 0; j < k; j++){
			if(mp[a[i * k + x + j]] != 0){
				pref2[i][mp[a[i * k + x + j]] - 1]++;
			}
		}
		for(int j = 0; j < c; j++){
			pref2[i + 1][j] = pref2[i][j];
		}
	}
	vector<int>ch(c);
	int ans1 = -1;
	for(int i = 0; i < m / k; i++){
		int zzz = 0;
		for(int j = 0; j < c; j++){
			if(i != 0){
				ch[j] = pref2[i][j] - pref1[i - 1][j];
			}
			else{
				ch[j] = pref2[0][j];
			}
			if(colvo[j] > ch[j]){
				zzz = 1;
			}
		}
		if(zzz == 0){
			ans1 = i;
			break;
		}
	}
	if(ans1 == -1){
		cout << -1;
		return 0;
	}
	vector<int>colvo2(c);
	vector<int>ans;
	for(int i = ans1 * k; i < ans1 * k + k + x; i++){
		if((int)ans.size() == x){
			break;
		}
		if(mp[a[i]] != 0){
			if(colvo2[mp[a[i]] - 1] < colvo[mp[a[i]] - 1]){
				colvo2[mp[a[i]] - 1]++;
			}
			else{
				ans.push_back(i);
			}
		}
		else{
			ans.push_back(i);
		}
	}
	cout << (int)ans.size() << '\n';
	for(int i = 0; i < (int)ans.size(); i++){
		cout << ans[i] + 1 << " ";
	}
	return 0;
}
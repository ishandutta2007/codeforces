#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;
const ll P1 = 735630697;
const ll P2 = 472881677;
const ll M1 = 1086218209;
const ll M2 = 1023893713;

int n, m;

void prework(){

}

void read(){

}

typedef pair<ll, ll> PLL;

PLL add(int x, PLL now){
	return PLL((now.first * P1 + x) % M1, (now.second * P2 + x) % M2);
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	cin >> n >> m;
	string s;
	getline(cin, s);
	map<PII, int> mp;
	for (int i = 1; i <= n; i++){
		getline(cin, s);
		ll r1 = 0, r2 = 0;
		for (int j = 0; j < s.length(); j++){
			r1 = (r1 * P1 + s[j]) % M1;
			r2 = (r2 * P2 + s[j]) % M2;
		}
		mp[PII((int)r1, (int)r2)]++;
	}
	for (int i = 1; i <= m; i++){
		getline(cin, s);
		int ans = 0;
		vector<PLL> now;
		now.push_back(PLL(0LL, 0LL));
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '?'){
				int m = now.size();
				now.resize(m * 6);
				for (int j = 0; j < m; j++){
					for (int k = 'a'; k <= 'e'; k++){
						now[(k - 'a' + 1) * m + j] = add(k, now[j]);
					}
				}
			}
			else{
				for (int j = 0; j < now.size(); j++){
					now[j] = add(s[i], now[j]);
				}
			}
		}
		sort(now.begin(), now.end());
		now.erase(unique(now.begin(), now.end()), now.end());
		for (int j = 0; j < now.size(); j++){
			ans += mp[PII(now[j].first, now[j].second)];
		}
		printf("%d\n", ans);
	}
}

void printans(){

}

int main(){
	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100100

map<string, int> cnt;
map<string, string> who;

int main(){
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	int n; cin >> n;
	while (n--){
		string s; cin >> s;
		set<string> subs;
		for (int i = 0; i < (int)s.size(); i++){
			string sub = "";
			for (int j = i; j < (int)s.size(); j++) sub.push_back(s[j]), subs.insert(sub);
		}
		for (set<string>::iterator it = subs.begin(); it != subs.end(); it++){
			string sub = *it;
			cnt[sub]++;
			who[sub] = s;
		}
	}

	int q; cin >> q;
	while (q--){
		string s; cin >> s;
		cout << cnt[s] << " ";
		if (cnt[s] == 0) cout << "-" << endl;
		else cout << who[s] << endl;
	}

	return 0;
}
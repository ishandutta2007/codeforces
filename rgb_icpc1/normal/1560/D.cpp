#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
string s[100];
string toStr(LL x) {
	string tmp = "";
	while(x) {
		tmp += '0' + (x % 10);
		x /= 10;
	}
	reverse(tmp.begin(), tmp.end());
	return tmp;
}
void init() {
	LL x = 1LL;
	int i = 0;
	s[i] = toStr(x);
	for(i = 1 ; i < 63 ; i ++) {
		x = x << 1;
		s[i] = toStr(x);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	init();
	int Tc;
	LL N;
	for(cin >> Tc ; Tc -- ; ) {
		cin >> N;
		string X = toStr(N);
		int rlt = INT_MAX;
		for(int i = 0 ; i < 63 ; i ++) {
			int taken = 0;
			int cur = 0;
			for(int j = 0 ; j < X.size() ; j ++) {
				if(X[j] == s[i][cur]) cur ++;
				else taken ++; 
			}
			taken += s[i].size() - cur;
			if(taken < rlt) rlt = taken;
		}
		cout << rlt << endl;
	}
}
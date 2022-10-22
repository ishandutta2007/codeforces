#include <bits/stdc++.h>
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int c[2][2];
int d[2][2];

const int mod = 1e9 + 7;

int fac[500007];
int invfac[500007];

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int mult(int a, int b){
	return (ll)a * b % mod;
}

int bp(int a, int k){
	if (k == 1) return a;
	if (k % 2 == 1){	
		return mult(bp(a, k - 1), a);
	} else {
		int q = bp(a, k / 2);
		return mult(q, q);
	}
}

int cnk(int n, int k){
	if (k < 0) return 1;
	///K > N;
	return mult(fac[n], mult(invfac[k], invfac[n - k]));
}

bool check(string s){
	d[0][0] = 0;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 0;
	for (int i = 0; i + 1 < s.size(); i++) d[s[i] - '0'][s[i + 1] - '0']++;
	return d[0][0] == c[0][0] && d[0][1] == c[0][1] && d[1][0] == c[1][0] && d[1][1] == c[1][1];
}

int func(int len, int c00, int c01, int c10, int c11){
	//cout << len << ' ' << c00 << c01 << c10 << c11 << endl;
	if (min(c00, min(c01, min(c10, c11))) < 0) return 0;
	if (len != c00 + c01 + c10 + c11) return 0;
	int g1 = c01, g0 = c10 + 1;
	if (g0 - g1 != 0 && g0 - g1 != 1) return 0;
	int need0 = g0 + c00 - 1, need1 = g1 + c11;
	if (need0 + need1 != len) return 0;
	if (g0 == 0 && c00 != 0) return 0;
	if (g1 == 0 && c11 != 0) return 0;
	int ans = mult(cnk(c00 + g0 - 1, g0 - 1), cnk(c11 + g1 - 1, g1 - 1));
	return ans;
}

int func2(int len, int c00, int c01, int c10, int c11){
	if (min(c00, min(c01, min(c10, c11))) < 0) return 0;
	if (len != c00 + c01 + c10 + c11) return 0;
	int g1 = c01 + 1, g0 = c10;
	if (g1 - g0 != 0 && g1 - g0 != 1) return 0;
	int need0 = g0 + c00, need1 = g1 + c11 - 1;
	if (need0 + need1 != len) return 0;
	if (g0 == 0 && c00 != 0) return 0;
	if (g1 == 0 && c11 != 0) return 0;
	int ans = mult(cnk(c00 + g0 - 1, g0 - 1), cnk(c11 + g1 - 1, g1 - 1));
	return ans;
}

int calc(string s){
	int ans = 0;
	if (c[0][0] == 0 && c[0][1] == 0 && c[1][0] == 0 && c[1][1] == 0 && s != "1") ans++;
	for (int i = 1; i <= (int)s.size() - 2; i++){
		add(ans, func2(i, c[0][0], c[0][1], c[1][0], c[1][1]));
	}
	d[0][0] = 0;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1' && i != 0){
			d[s[i - 1] - '0'][1]--;
			d[s[i - 1] - '0'][0]++;
			add(ans, func((int)s.size() - i - 1, c[0][0] - d[0][0], c[0][1] - d[0][1], c[1][0] - d[1][0], c[1][1] - d[1][1]));
			d[s[i - 1] - '0'][1]++;
			d[s[i - 1] - '0'][0]--;
		}
		if (i + 1 < s.size()) d[s[i] - '0'][s[i + 1] - '0']++;
	}
	return ans + check(s);	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	/*for (int mask = 0; mask < (1 << 5); mask++){
		int f = 0;
		int w[2][2] = {0, 0, 0, 0}, last;
		for (int i = 10; i >= 0; i--){
			if (f){
				w[last][((mask >> i) & 1)]++;
			}
			if ((mask >> i) & 1) f = 1;
			if (f) cout << ((mask >> i) & 1);
			last = ((mask >> i) & 1);
		} 
		cout << "  " << w[0][0] << w[0][1] << w[1][0] << w[1][1];
		cout << endl;
	}
	cout << endl << endl;*/
	//exit(0);
	fac[0] = 1;
	for (int i = 1; i < 500007; i++) fac[i] = mult(fac[i - 1], i);
	invfac[500007 - 1] = bp(fac[500007 - 1], mod - 2);
	for (int i = 500007 - 2; i >= 0; i--) invfac[i] = mult(invfac[i + 1], i + 1);
	string s1, s2;
	cin >> s1 >> s2 >> c[0][0] >> c[0][1] >> c[1][0] >> c[1][1];
	int ans = calc(s2) - calc(s1);
	if (ans < 0) ans += mod;
	add(ans, check(s1));
	cout << ans;	
}
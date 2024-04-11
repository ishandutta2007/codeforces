#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

const int NN = 1011;
char s[NN];
int n;
int solve() {
	cin >> n;
	scanf("%s", s);
	int fir=-1, sec;
	for(int i=0; s[i]; i++) if(s[i] == '1') {
		if(fir==-1) fir = i;
		sec = i;
	}
	if(fir == -1) return cout <<n<<endl, 0;
	cout << 2 * n - min(fir, n-sec-1)*2 << endl;
}


int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
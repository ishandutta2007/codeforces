#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 3000000; 

ll a10[1000]; 
char st[maxn];

ll getnum(ll i, ll msk, int d) {
	ll ans = 0; 
	ll x = i/a10[d]; 
	for (int j = d-1; j >= 0; --j)
		if ((msk >> j) & 1) {
			ans += x; 
			x = i/a10[j]%10; 
		}
		else x = x * 10 + i/a10[j]%10; 
	ans += x; 
	return ans; 
}

int getd(ll x) {
	ll d; 
	for (d = 17; d >= 0; --d) 
		if (x/a10[d] > 0 || d == 0) break; 
	return d; 
}

vector<char> s1, s2; 

bool dfs1(ll x) {
	int d = getd(x); 
	for (int msk = (1ll<<d)-1; msk >= 0; msk--) {
		if (getnum(x,msk,d) < 10) {
			s1.clear(); 
			for (int i = d; i >= 0; --i) {
				if ((msk>>i)&1) s1.pb('+');
				s1.pb(x/a10[i]%10+'0'); 
			}
			return true; 
		}
	}	
	return false; 
}

bool dfs2(ll x) {
	int d = getd(x); 
	for (int msk = (1ll<<d)-1; msk >= 0; msk--) {
		if (dfs1(getnum(x,msk,d))) {
			s2.clear(); 
			for (int i = d; i >= 0; --i) {
				if ((msk>>i)&1) s2.pb('+');
				s2.pb(x/a10[i]%10+'0'); 
			}
			return true; 
		}
	}	
	return false; 
}

vector<int> cho; 
mt19937 myrand(time(0)); 

int main() {
	a10[0] = 1; 
	
	for (int i = 1; i <= 18; ++i) a10[i] = a10[i-1] * 10; 
	
	int len; 
	vector<string> s; s.clear(); 
	ll sum = 0; 
	scanf( "%d%s", &len, st );
	for (int i = 0; i < len; ++i) {
		s.pb({st[i]}); 
		sum += st[i]-'0'; 
	}
	while (!dfs2(sum)) {
		cho.clear(); 
		for (int i = 0; i < (int)s.size()-1; ++i)
			if (stoi(s[i]) != 0) cho.pb(i); 
		int x = cho[myrand() % cho.size()]; 
		sum -= stoi(s[x]); sum -= stoi(s[x+1]); 
		s[x] = s[x] + s[x+1]; sum += stoi(s[x]); 
		s.erase(s.begin()+x+1); 
	}
	
	for (int i = 0; i < (int)s.size(); ++i) {
		if (i != 0) printf( "+" ); 
		printf( "%s", s[i].c_str()); 
	}
	puts( "" ); 
	for (auto i : s2) printf( "%c", i ); 
	puts( "" ); 
	for (auto i : s1) printf( "%c", i ); 
	puts( "" ); 
}
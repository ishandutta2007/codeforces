#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10, MAX = 3e6 + 10, mod = 1e9 + 7;

int f[MAX];

void Kmp(string s){
    int n = sz(s);
    for(int i = 2; i <= n; i++){
	f[i] = f[i-1];
	while(f[i] > 0 && s[f[i]] != s[i-1])
	    f[i] = f[f[i]];
	f[i]+= s[f[i]] == s[i-1];
    }
}
int kmp(string text, string pattern){
    Kmp(pattern);
    int n = sz(pattern);
    int now = 0, ans = 0;
    for(char c : text){
	while(now > 0 && pattern[now] != c)
	    now = f[now];
	now+= pattern[now] == c;
	if(now == n)
	    ans++, now = f[now];
    }
    return ans;
}
	
int add[26];
int pw[maxn];
int bins[maxn][26];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    pw[0] = 1;
    for(int i = 1; i < maxn; i++)
	pw[i] = 2ll * pw[i-1] % mod;

    int n, q;
    cin >> n >> q;
    string _s, T;
    cin >> _s >> T;

    for(int i = 0; i < sz(T); i++){
	for(int j = 0; j < 26; j++){
	    bins[i][j] = (2ll * (i == 0 ? 0 : bins[i-1][j]) + (T[i]-'a' == j)) %mod;
	}
    }
    
    while(q--){
	int numb;
	cin >> numb;
	string name;
	cin >> name;
	string s = _s;
	int now = 0;
	while(sz(name) > sz(s) && now < numb){
	    s = s + T[now] + s;
	    now++;
	}
	int ans = 0;
	if(sz(name) <= sz(s)){
	    int val = kmp(s, name);
	    string PR = s.substr(sz(s) - (sz(name)-1)), SF = s.substr(0, sz(name)-1);
	    for(int i = 0; i < 26; i++){
		string x = PR + char('a' + i) + SF;
		add[i] = kmp(x, name);
	    }
	    if(numb > 0){
		for(int i = 0; i < 26; i++){
		    int num = (1ll * bins[numb-1][i] - (now == 0 ? 0 : (1ll * bins[now-1][i] * pw[numb-now] %mod))) %mod;
		    ans = (1ll * ans + 1ll * add[i] * num) %mod;
		}
	    }
	    ans = (1ll * ans + 1ll * pw[numb-now] * val) %mod;
	    if(ans < 0)
		ans+= mod;
	}
	cout << ans << "\n";
    }
    return 0;
}
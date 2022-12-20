#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10;

namespace StrAlgo{
    // 1 base
    vector<int> Kmp(string s){
	int n = sz(s);
	vector<int> ans(n + 1);
	for(int i = 2; i <= n; i++){
	    ans[i] = ans[i-1];
	    while(ans[i] > 0 && s[ans[i]] != s[i-1])
		ans[i] = ans[ans[i]];
	    ans[i]+= s[ans[i]] == s[i-1];
	}
	return ans;
    }
    vector<int> Z(string s){
	int n = sz(s);
	vector<int> ans(n + 1);
	int L = -1, R = -1;
	// [L R)
	// ans[1] is 0
	for(int i = 2; i <= n; i++){
	    if(i < R)
		ans[i] = min(ans[i-L+1], R-i);
	    else
		L = i, R = i;
	    while(i + ans[i] <= n && s[i-1 + ans[i]] == s[ans[i]])
		ans[i]++;
	    if(i + ans[i] > R)
		L = i, R = i + ans[i];
	}
	return ans;
    }
};

void print(string s, int len){
    if(len == 0)
	cout << "Just a legend\n";
    else
	cout << s.substr(sz(s)-len) << "\n";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    string s;
    cin >> s;
    int n = sz(s);
    vector<int> z = StrAlgo::Z(s);
    int ln = 0;
    for(int i = 2; i <= n; i++){
	ln = max(ln, z[i] - (i + z[i] == n + 1)); 
    }
    for(int i = 2; i <= n; i++){
	if(i + z[i] == n + 1 && z[i] <= ln)
	    return cout << s.substr(i-1) << endl, 0;
    }
    return cout << "Just a legend\n", 0;
}
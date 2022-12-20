#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

bool solve(){
    string s;
    cin >> s;
    if(sz(s) & 1)
	return 0;
    int can = sz(s) / 2;
    for(char c : s){
	can -= c == '(';
    }
    if(can < 0)
	return 0;
    int now = 0;
    for(char c : s){
	if(c == '(')
	    now++;
	else if(c == ')')
	    now--;
	else if(can > 0)
	    can--, now++;
	else
	    now--;
	if(now < 0)
	    return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << (solve() ? "YES\n" : "NO\n");
    }
}
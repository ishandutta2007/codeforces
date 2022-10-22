#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()

string s, ac = "CODEFORCES";

int main(){
    cin >> s;
    rep(i, s.size()){
	for(int j = i; j < s.size(); ++j){ //[i,j]
	    string t = "";
	    rep(k, i) t.pb(s[k]);
	    for(int k = j + 1; k < s.size(); ++k) t.pb(s[k]);
	    if(t == ac){
		puts("YES");
		return 0;
	    }
	}
    }
    puts("NO");
    return 0;
}
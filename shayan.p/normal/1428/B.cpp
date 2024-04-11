#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 3e5 + 10;

bool check(string s, char c){
    for(char ch : s){
	if(ch != '-' && ch != c)
	    return 0;
    }
    return 1;
}
int solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(check(s, '<') || check(s, '>'))
	return n;
    int ans = 0;
    for(int i = 0; i < n; i++){
	ans+= s[i] == '-' || s[(i+1) % n] == '-';
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
    return 0;
}
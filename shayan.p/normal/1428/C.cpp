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

int solve(){
    string s;
    cin >> s;
    int cnt = 0;
    for(char c : s){
	if(c == 'B'){
	    if(cnt == 0)
		cnt++;
	    else
		cnt--;
	}
	else{
	    cnt++;
	}
    }
    return cnt;
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
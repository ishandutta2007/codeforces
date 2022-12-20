// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int toInt(string s){
    stringstream ss;
    ss << s;
    int x;
    ss >> x;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s;
    cin >> s;
    int ans = -1;
    for(int i = 1; i < sz(s); i++){
	for(int j = i+1; j < sz(s); j++){
	    if((s[0] != '0' || i == 1) && (s[i] != '0' || i+1 == j) && (s[j] != '0' || j+1 == sz(s)) && sz(s)-j < 8 && j-i < 8 && i < 8){
		int A = toInt(s.substr(0, i)), B = toInt(s.substr(i, j-i)), C = toInt(s.substr(j, sz(s)-j));
		if(max({A, B, C}) <= 1000000)
		    ans = max(ans, A+B+C);
	    }
	}
    }
    return cout << ans << endl, 0;
}
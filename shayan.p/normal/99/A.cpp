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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s;
    cin >> s;
    while(s[sz(s)-2] != '.')
	s.pop_back();	
    if(s[sz(s)-3] == '9')
	return cout << "GOTO Vasilisa.\n", 0;
    if(s.back() >= '5')
	s.pop_back(), s.pop_back(), s[sz(s)-1]++;
    else
	s.pop_back(), s.pop_back();
    return cout << s << endl, 0;
}
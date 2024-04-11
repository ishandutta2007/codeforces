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

vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s;
    cin >> s;
    map<char, int> mp;
    for(char c : s)
	mp[c]++;
    for(pii p : mp)
	vec.PB(p.S);
    sort(vec.begin(), vec.end());
    if(vec.back() >= 5)
	return cout << 1 << endl, 0;
    if(vec.back() == 4)
	return cout << 2 << endl, 0;
    if(vec.back() == 3){
	if(sz(vec) == 2)
	    return cout << 2 << endl, 0;
	if(sz(vec) == 3)
	    return cout << 3 << endl, 0;
	if(sz(vec) == 4)
	    return cout << 4 + 1 << endl, 0;
    }
    int B = 6 - sz(vec), A = 6 - 2*B;
    if(A > 2)
	return cout << (24 >> B) + (6 >> B) << endl, 0;
    if(A > 0)
	return cout << (24 >> B) + 2 << endl, 0;
    if(A == 0)
	return cout << 6 << endl, 0;
}
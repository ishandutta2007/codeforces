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
    int n = sz(s);
    int cnt1 = 0, cnt2 = 0;

    for(char c : s)
	cnt2+= c == ')';
    int pos = 0;
    if(cnt1 != cnt2){
	for(int i = 0; i < n; i++){
	    cnt2-= s[i] == ')';
	    cnt1+= s[i] == '(';
	    if(cnt1 == cnt2)
		pos = i+1;
	}
    }
    vector<int> vec;
    for(int i = 0; i < n; i++){
	if(i < pos && s[i] == '(')
	    vec.PB(i+1);
	if(i >= pos && s[i] == ')')
	    vec.PB(i+1);
    }
    if(vec.empty()){
	cout << 0 << endl;
    }
    else{
	cout << 1 << endl;
	cout << sz(vec) << endl;
	for(int x : vec)
	    cout << x << " ";
	cout << endl;
    }
    return 0;
}
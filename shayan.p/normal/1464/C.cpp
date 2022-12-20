#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 26;

int cnt[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    ll T;
    cin >> n >> T;
    string s;
    cin >> s;
    T-= 1<<(s.back()-'a');
    s.pop_back();    
    T+= 1<<(s.back()-'a');
    s.pop_back();
    for(char c : s){
	cnt[c-'a']++;
    }
    for(int i = 0; i < 26; i++){
	T+= (1ll<<i) * cnt[i];	
    }
    if((T & 1) || T < 0)
	return cout << "No\n", 0;
    T/= 2;
    for(int i = 25; i >= 0; i--){
	ll X = min(1ll*cnt[i], T>>i);
	T-= (1ll<<i) * X;
    }
    return cout << (T == 0 ? "Yes" : "No") << endl, 0;
}
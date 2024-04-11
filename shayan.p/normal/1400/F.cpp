// Oh damn! Suddenly you're free to fly...

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

int dp[1<<20], tmp[1<<20], x;
int divi;

int f(int msk, int num){
    if(num > x)
	return 0;
    if(num == x)
	return -1;
    if(x % num == 0)
	return 0;
    if(bit(msk, x-num-1))
	return -1;
    int ans = ((ll(msk) << num) | (1<<(num-1))) & ((1<<(x-1))-1);
    int bad = ans & divi;
    if(bad == 0)
	return ans;
    int id = __builtin_ctz(bad);
    ans&= (1<<id)-1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s;
    cin >> s;
    cin >> x;
    vector<int> valid_masks;
    for(int i = 1; i < x; i++){
	if(x % i == 0)
	    divi|= 1<<(i-1);
    }
    for(int msk = 0; msk < (1<<(x-1)); msk++){ // bit i -> vojood i+1
	if(bit(msk, 0))
	    continue;
	bool bad = (divi & msk) != 0;
	for(int i = 0; i < x-1; i++){
	    if(bit(msk, i) && ((ll(divi) << (i+1)) & (ll(msk))))
		bad = 1;
	}
	if(!bad)
	    valid_masks.PB(msk);
    }
    for(int i = sz(s)-1; i >= 0; i--){
	for(int msk : valid_masks)
	    tmp[msk] = dp[msk] + 1;
	for(int msk : valid_masks){
	    int to = f(msk, s[i] - '0');
	    if(to != -1)
		tmp[msk] = min(tmp[msk], dp[to]);
	}
	for(int msk : valid_masks){
	    dp[msk] = tmp[msk];
	}
    }
    return cout << dp[0] << endl, 0;
}
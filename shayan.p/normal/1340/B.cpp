// Never let them see you bleed...
// Shayan.P  2020-04-23

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2010, mod = 1e9 + 7, inf = 1e9 + 10;

string d[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int MSK[10];
bitset<maxn * 7> dp[maxn];
int ans[maxn];
string s[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 0; i < 10; i++)
	for(int j = 0; j < 7; j++)
	    MSK[i]|= (d[i][j] == '1') << j;
    
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
	cin >> s[i];
    }
    dp[n][0] = 1;
    for(int i = n-1; i >= 0; i--){
	int msk = 0;
	for(int j = 0; j < 7; j++)
	    msk|= (s[i][j] == '1') << j;	    
	for(int j = 0; j < 10; j++){
	    if((msk & MSK[j]) != msk)
		continue;
	    dp[i] = (dp[i] | (dp[i+1] << __builtin_popcount(msk ^ MSK[j])));
	}
    }
    if(dp[0][k] == 0)
	return cout << -1 << endl, 0;    
    for(int i = 0; i < n; i++){
	int msk = 0;
	for(int j = 0; j < 7; j++)
	    msk|= (s[i][j] == '1') << j;
	int ls = -1;
	for(int j = 0; j < 10; j++){
	    if((msk & MSK[j]) != msk)
		continue;
	    int num = k - __builtin_popcount(msk ^ MSK[j]);
	    if(num >= 0 && dp[i+1][num])
		ans[i] = j, ls = num;
	}
	assert(ls != -1);
	k = ls;
	cout << ans[i];
    }
    return cout << endl, 0;
}
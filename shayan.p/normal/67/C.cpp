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

const int maxn = 4010, mod = 1e9 + 7, inf = 1e9 + 10;

int dp[maxn][maxn];
int bef1[maxn][26], bef2[maxn][26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int ins, del, rep, swp;
    cin >> ins >> del >> rep >> swp;
    string A, B;
    cin >> A >> B;

    for(int i = 0; i < 26; i++){
	bef1[0][i] = bef2[0][i] = 0;
    }
    for(int i = 1; i <= sz(A); i++){
	memcpy(bef1[i], bef1[i-1], sizeof bef1[i]);
	bef1[i][A[i-1]-'a'] = i;
    }
    for(int i = 1; i <= sz(B); i++){
	memcpy(bef2[i], bef2[i-1], sizeof bef2[i]);
	bef2[i][B[i-1]-'a'] = i;
    }
    
    for(int i = 0; i <= sz(A); i++){
	for(int j = 0; j <= sz(B); j++){
	    if(j == 0){
		dp[i][j] = del * i;
		continue;
	    }
	    if(i == 0){
		dp[i][j] = ins * j;
		continue;
	    }
	    dp[i][j] = min({dp[i-1][j] + del, dp[i][j-1] + ins, dp[i-1][j-1] + (A[i-1] == B[j-1] ? 0 : rep)});
	    if(i >= 2 && j >=2){
		for(int cheat1 : {0,1}){
		    for(int cheat2 : {0,1}){
			int I = cheat1 ? i-1 : bef1[i-1][B[j-1]-'a'];
			int J = cheat2 ? j-1 : bef2[j-1][A[i-1]-'a'];
			if(I != 0 && J != 0)
			    dp[i][j] = min(dp[i][j], swp + dp[I-1][J-1] + del * (i-I-1) + ins * (j-J-1) + (cheat1 ? rep : 0) + (cheat2 ? rep : 0));
		    }
		}
	    }
	}
    }
    return cout << dp[sz(A)][sz(B)] << endl, 0;
}
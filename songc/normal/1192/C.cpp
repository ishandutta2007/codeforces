#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
LL C[12][62][62], ans;
LL D[12][70][70][70];

struct String{
	vector<int> str;
	bool operator<(const String &r)const{
		for (int i=0; i<str.size(); i++) if (str[i] != r.str[i]) return str[i] < r.str[i];
		return false;
	}
	bool operator==(const String &r)const{
		for (int i=0; i<str.size(); i++) if (str[i] != r.str[i]) return false;
		return true;
	}
};
vector<String> S[12];

int ctoi(char ch){
	if ('0' <= ch && ch <= '9') return ch - '0';
	if ('a' <= ch && ch <= 'z') return 10 + ch - 'a';
	return 36 + ch - 'A';
}

int main(){
	char t[20];
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		scanf("%s", t);
		int l = strlen(t);
		S[l].push_back(String());
		for (int i=0; i<l; i++) S[l].back().str.push_back(ctoi(t[i]));
		S[l].push_back(String());
		for (int i=l-1; i>=0; i--) S[l].back().str.push_back(ctoi(t[i]));
	}
	for (int l=3; l<=10; l++){
		sort(S[l].begin(), S[l].end());
		S[l].erase(unique(S[l].begin(), S[l].end()), S[l].end());
		for (String s : S[l]) C[l][s.str[0]][s.str[l-1]]++;
		for (int i=0; i<62; i++) {
			for (int p=0; p<62; p++) {
                if (!C[i][p]) continue;
                for (int q=p; q<62; q++) {
                    if (!C[i][q]) continue;
                    for (int r=q; r<62; r++){
                        if (!C[i][r]) continue;
                        D[l][p][q][r] = (D[l][p][q][r] + (C[l][i][p] * C[l][i][q] % MOD * C[l][i][r] % MOD)) % MOD;
                    }
                }
			}
		}
		for (int p=0; p<62; p++) for (int q=p; q<62; q++) for (int r=q; r<62; r++) for (int s=r; s<62; s++){
			int cnt;
			if (p == s) cnt = 1;
			else if (p == r || q == s) cnt = 4;
			else if (p == q && r == s) cnt = 6;
			else if (p == q || q == r || r == s) cnt = 12;
			else cnt = 24;
			ans = (ans + (D[l][p][q][r] * D[l][p][q][s] % MOD * D[l][p][r][s] % MOD * D[l][q][r][s] % MOD * cnt % MOD)) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
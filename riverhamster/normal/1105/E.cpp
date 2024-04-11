#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
const int N = 45, L = 200005;
using namespace std;
typedef long long ll;
bool c[N][N], msk[L], ill[(1<<20)+5], ill1[(1<<20)+5];
int type[L], ks[L];
int f1[(1<<20)+5], f2[(1<<20)+5];
int n, m;
template<typename T> inline void in(T &x){
	register char ch; x = 0;
	while(isspace(ch = getchar()));
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
}
map<string, int> key;

inline bool isill(int x, int k, int off){ //off
	for(int i=0; i<(m+1)>>1; i++)
		if((x & (1 << i)) && c[i+off][k+off]) return true;
	return false;
}

int main(){
	// freopen("cf1105e.in", "r", stdin);
	// freopen("cf1105e.out", "w", stdout);
	int tot = 0, s1, s2;
	string s;
	in(n); in(m);
	for(int i=1; i<=n; i++){
		in(type[i]);
		if(type[i] == 2){
			cin >> s;
			if(!key.count(s)) key[s] = ks[i] = ++tot;
			else ks[i] = key[s];
			msk[ks[i]] = true;
			for(int j=1; j<=tot; j++) c[ks[i]][j] |= msk[j];
		}
		else for(int j=i-1; j>0&&type[j]!=1; j--) msk[ks[j]] = false;
	}
	// printf("%ldms\n", clock());
	for(int i=1; i<=m; i++)
		for(int j=1; j<=m; j++)
			c[i][j] |= c[j][i];
	for(int i=1; i<=m; i++) c[i][i] = false;
	s1 = (m+1) / 2; s2 = m - s1;
	for(int i=0; i<(1<<s1); i++){
		ill1[i] = ill[i];
		for(int j=0; j<s1; j++){
			if((i & (1 << j)) == 0){
				if(ill[i] || isill(i, j, 1)) ill[i|(1<<j)] = true;
				f1[i|(1<<j)] = max(f1[i|(1<<j)], f1[i] + (int)!ill[i|(1<<j)]);
			}
		}
	}
	memset(ill, 0, sizeof ill);
	// printf("%ldms\n", clock());
	// puts("DP s2");
	for(int i=0; i<(1<<s2); i++){
		for(int j=0; j<s2; j++)
			if((i & (1 << j)) == 0){
				if(ill[i] || isill(i, j, s1+1)) ill[i|(1<<j)] = true;
				f2[i|(1<<j)] = max(f2[i|(1<<j)], f2[i] + (int)!ill[i|(1<<j)]);
			}
	}
	int msk2 = 0, ans = 0;
	for(int i=0; i<(1<<s1); i++){
		if(!ill1[i]){
			msk2 = (1 << s2) - 1;
			for(int p=1; p<=s1; p++){
				if(i & (1<<(p-1)))
					for(int q=1; q<=s2; q++)
						if(c[p][s1+q]) msk2 &= (0xffffffff ^ (1 << (q-1)));
				if(f1[i] + f2[msk2] < ans) break;
			}
			ans = max(ans, f1[i] + f2[msk2]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
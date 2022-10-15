#include <cstdio>
#include <iostream>
#define Maxn 5001

using namespace std;

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int len , n , cnt[Maxn][Maxn];
bool pri[Maxn][Maxn];
string s;

int main(){
	cin >> s;
	len = s.size();
	s = " " + s;
	for(int i = 1 ; i <= len ; i++){
		pri[i][i] = true;
		cnt[i][i] = 1;
	}
	for(int i = 2 ; i <= len ; i++)
		if(s[i - 1] == s[i]){
			pri[i - 1][i] = true;
			cnt[i - 1][i] = 3;
		}else
			cnt[i - 1][i] = 2;
	for(int l = 3 ; l <= len ; l++)
		for(int i = 1 ; i <= len ; i++){
			int j = i + l - 1;
			if(j > len)
				break;
			if(s[i] == s[j])
				pri[i][j] = pri[i + 1][j - 1];
			cnt[i][j] = pri[i][j] + cnt[i + 1][j] + cnt[i][j - 1] - cnt[i + 1][j - 1];
		}
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		int l = Read() , r = Read();
		printf("%d\n" , cnt[l][r]);
	}
	return 0;
}

// By Sooke.
// CF245H Queries for Number of Palindromes.
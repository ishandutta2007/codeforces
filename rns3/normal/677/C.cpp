#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int f[101];

int calc(char c){
    int x = 0;
    if('0' <= c && c <= '9') x = c - '0';
    if('A' <= c && c <= 'Z') x = c - 'A' + 10;
	if('a' <= c && c <= 'z') x = c - 'a' + 36;
	if(c == '-') x = 62;
	if(c == '_') x = 63;
	return f[x];
}

char s[1000001];

int main() {
    scanf("%s", s);
    for(int i = 0; i < 64; i ++) {
        for(int j = 0; j < 64; j ++) {
			for(int k = 0; k < 64; k ++) {
				if((j & k) == i) f[i] ++;
			}
        }
    }
    int ans = 1;
    for(int i = 0; s[i]; i ++) ans = 1ll * ans * calc(s[i]) % mod;
    cout << ans << endl;
}
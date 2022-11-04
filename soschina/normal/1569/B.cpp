#include <cstdio>
#include <cstring>
using namespace std;
const int N = 52;

int t, n, win[N], len;
char s[N], mp[N][N];

int main(){
	scanf("%d", &t);
	while(t--){
		memset(mp, 0, sizeof(mp));
		len = 0;
		scanf("%d%s", &n, s + 1);
		for(int i = 1; i <= n; i++) 
			if(s[i] == '2') win[++len] = i;
		if(len && len <= 2){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1; i < len; i++){
			mp[win[i]][win[i + 1]] = '+';
			mp[win[i + 1]][win[i]] = '-';
		}
		mp[win[len]][win[1]] = '+';
		mp[win[1]][win[len]] = '-';
		for(int i = 1; i <= n; i++)
			mp[i][i] = 'X';
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				putchar(mp[i][j] ? mp[i][j] : '=');
			putchar('\n');
		}
	}
	return 0;
}
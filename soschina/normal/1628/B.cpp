#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 1, A = 26 * 26, B = 26 * 26 * 26;

int t, n;
char s[N][4];
bool a2[A], a3[A], b[B], ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = false;
		memset(a2, 0, sizeof(a2));
		memset(a3, 0, sizeof(a3));
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%s", s[i]);
			int m = strlen(s[i]);
			if(m == 1) ans = true;
			else if(m == 2){
				if(s[i][0] == s[i][1]) ans = true;
				int hash = (s[i][1] - 'a') * 26 + s[i][0] - 'a';
				if(a2[hash] || a3[hash]) ans = true;
				a2[(s[i][0] - 'a') * 26 + s[i][1] - 'a'] = true;
			}else{
				if(s[i][0] == s[i][2]) ans = true;
				if(a2[(s[i][2] - 'a') * 26 + s[i][1] - 'a'] || b[(s[i][2] - 'a') * 26 * 26 + (s[i][1] - 'a') * 26 + s[i][0] - 'a']) ans = true;
				a3[(s[i][0] - 'a') * 26 + s[i][1] - 'a'] = true;
				b[(s[i][0] - 'a') * 26 * 26 + (s[i][1] - 'a') * 26 + s[i][2] - 'a'] = true;
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
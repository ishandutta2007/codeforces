#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 100005;
char s[N];
int sum[N], nxt[N][2];
int n, k;

int gsum(int x, int y, bool type){
	// printf("gsum %d %d %d\n", x, y, (int)type);
	if(y < x) return 0;
	if(y > n) y = n+1;
	if(x < 1) x = 1;
	if(type) return sum[y] - sum[x-1];
	else return (y - x + 1) - (sum[y] - sum[x - 1]);
}
void precal(){
	for(int i=1; i<=n; i++)
		sum[i] = sum[i-1] + s[i] - '0';
	for(int i=n; i>=1; i--){
		nxt[i][0] = nxt[i+1][0]; nxt[i][1] = nxt[i+1][1];
		nxt[i][s[i] - '0'] = i;
		// printf("nxt[%d][0] = %d, nxt[%d][1] = %d\n", i, nxt[i][0], i, nxt[i][1]);
	}
}
bool check_1st(){
	for(int i=1; i<=n-k+1; i++){
		for(int j=0; j<=1; j++)
			if(gsum(1, i-1, j) + gsum(i+k, n, j) == n - k) return true;
	}
	return false;
}
bool check_2nd(){
	bool flag;
	for(int i=1; i<=n-k+1; i++){
		for(int j=0; j<=1; j++){
			flag = false;
			if(gsum(1, i-1, j) == i-1 && i+k-1 + nxt[i+k][j^1]-1-(i+k)+1 + min(k, n-nxt[i+k][j^1]+1) + gsum(nxt[i+k][j^1]+k, n, j)  == n) flag = true;
			if(gsum(i+k, n, j) == n-(i+k) + 1 && nxt[1][j^1]-1 + min(k, (i-1)-nxt[1][j^1]+1) + gsum(nxt[1][j^1]+k, i-1, j) + n-i+1 == n) flag = true;
			if(!flag){
				// printf("change [%d, %d] -> %d: Will draw.\n", i, i+k-1, j);
				// printf("Change 2nd sequence: %d Change 1st sequence: %d\n", (int)(gsum(1, i-1, j) == i-1), (int)(gsum(i+k, n, j) == n-(i+k) + 1));
				// printf("%d + %d + %d + %d\n", i+k-1, pre[n][j^1]-1-(i+k)+1, min(k, n-pre[n][j^1]+1), gsum(pre[n][j^1]+k-1, n, j));
				// printf("gsum %d %d %d = %d VS %d\n", i+k, n, j, gsum(i+k, n, j), n-(i+k)+1);
				return false;
			}
		}
	}
	return true;
}

int main(){
	// File("cf1190c");
	in(n); in(k);
	scanf("%s", s+1);
	// puts(s+1);
	precal();
	if(check_1st()) puts("tokitsukaze");
	else if(check_2nd()) puts("quailty");
	else puts("once again");
	return 0;
}
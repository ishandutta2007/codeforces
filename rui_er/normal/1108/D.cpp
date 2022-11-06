//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, ans; char s[N];

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	rep(i, 2, n) {
		if(s[i] == s[i-1]) {
			if(i == n || s[i-1] == s[i+1]) s[i] = s[i-1] == 'B' ? 'R' : 'B';
			else s[i] = 'R' ^ 'G' ^ 'B' ^ s[i-1] ^ s[i+1];
			++ans;
		}
	}
	printf("%d\n%s\n", ans, s+1);
	return 0;
}
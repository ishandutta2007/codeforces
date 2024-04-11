//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int T, n, k, buc[26];
string a, b;

int main() {
	scanf("%d", &T);
	while(T--) {
		fil(buc, 0);
		scanf("%d%d", &n, &k);
		cin>>a>>b;
		rep(i, 0, n-1) ++buc[a[i]-'a'], --buc[b[i]-'a'];
		int s = 0, _ = 0;
		per(i, 25, 0) {s -= buc[i]; if(s < 0 || buc[i] % k) {_ = 1; break;}}
		puts(_?"No":"Yes");
	}
	return 0;
}
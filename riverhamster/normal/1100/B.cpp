#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
int a[100005];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
multiset<int> S;

int main(){
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	int n, p, dif, con = 0;
	in(p); in(n);
	for(int i=1; i<=p; i++) S.insert(0);
	for(int i=1; i<=n; i++){
		in(dif);
		// printf("Size = %llu\n", S.size()); fflush(stdout);
		S.erase(S.find(a[dif]));
		// printf("Size = %llu\n", S.size()); fflush(stdout);
		// puts("Executed"); fflush(stdout);
		++a[dif];
		S.insert(a[dif]);
		// puts("Inserted"); fflush(stdout);
		// printf("Size = %llu\n", S.size()); fflush(stdout);
		// if(S.empty()) puts("Begin failed"), fflush(stdout);
		// printf("*S.begin() = %d\n", *S.begin()); fflush(stdout);
		if(*S.begin() > con){
			++con;
			putchar('1');
		}
		else putchar('0');
	}
	return 0;
}
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
int a[N];

int main(){
	// File("b");
	ll n;
	ll last = 0, sum = 0;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	sort(a+1, a+1+n);
	bool all0 = true, over3 = false, two0 = false, nodown = false;
	int two = 0;
	a[0] = -2;
	for(int i=1; i<=n; i++){
		if(a[i] != 0) all0 = false;
		if(a[i] == a[i-1] && a[i-1] == a[i-2]){
			over3 = true; break;
		}
		if(a[i] == a[i-1]){
			++two;
			if(a[i-2] == a[i] - 1){
				nodown = true;
				break;
			}
		}
		sum += a[i];
	}
	if(a[1] == 0 && a[2] == 0) two0 = true;
	// printf("all0 %d over3 %d two0 %d\n", (int)all0, (int)over3, (int)two0);
	if(all0 || over3 || two0 || two >= 2 || nodown){
		puts("cslnb");
		return 0;
	}
	last = n * (n-1) / 2;
	// printf("Sum = %lld last = %lld\n", sum, last);
	if((sum - last) % 2 == 0) puts("cslnb");
	else puts("sjfnb");
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

int t, a[3];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", a, a + 1, a + 2);
		sort(a, a + 3);
		puts(a[0] + a[1] == a[2] || (a[0] == a[1] && (a[2] & 1) == 0) || ((a[0] & 1) == 0 && a[1] == a[2]) ? "YES" : "NO");
	}
	return 0;
}
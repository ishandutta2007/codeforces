#include <cstdio>
#include <iostream>
using namespace std;

int t, n, m, a, b, ans1, ans2;

int main(){
	scanf("%d", &t);
	while(t--){
		ans1 = ans2 = 0;
		scanf("%d%d", &n, &m);
		a = n, b = m;
		while((a | b) != b)
			ans1++, a++;
		if(a != b) ans1++;
		a = n, b = m;
		while((a | b) != b)
			ans2++, b++;
		ans2++;
		printf("%d\n", min(ans1, ans2));
	}
	return 0;
}
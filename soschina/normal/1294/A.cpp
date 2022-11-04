#include <cstdio>
#include <iostream>
using namespace std;

int t, a[3], n, maxa;

int main(){
	scanf("%d", &t);
	while(t--){
		maxa = 0;
		for(int i = 0; i < 3; i++){
			scanf("%d", a + i);
			maxa = max(maxa, a[i]);
		}
		scanf("%d", &n);
		for(int i = 0; i < 3; i++)
			n -= maxa - a[i];
		printf("%s\n", n >= 0 && n % 3 == 0 ? "YES" : "NO");
	}
	return 0;
}
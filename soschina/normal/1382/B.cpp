#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];
bool state;

int main(){
	scanf("%d", &t);
	while(t--){
		state = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		for(int i = n; i; i--){
			if(a[i] == 1 && state) state = 0;
			else state = 1;
		}
		puts(state ? "First" : "Second");
	}
	return 0;
}
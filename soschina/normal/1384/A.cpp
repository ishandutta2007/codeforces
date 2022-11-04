#include <cstdio>
using namespace std;

int t, n, a;
char s[52];

int main(){
	for(int i = 1; i <= 50; i++)
		s[i] = 'a';
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%s\n", s + 1);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a);
			for(int j = a + 1; j <= 50; j++)
				s[j] = s[j] == 'a' ? 'b' : 'a';
			printf("%s\n", s + 1);
		}
	}
	return 0;
}
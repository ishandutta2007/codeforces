#include <cstdio>
using namespace std;

int t, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		a--;
		b ^= (a & 1) ^ ((a >> 1) & 1);
		for(int i = 1; i < 32; i++)
			if(((a >> i) & 1) && !(a & 1)) b ^= 1 << i;
		a++;
		if(!b) printf("%d\n", a);
		else if(b == a) printf("%d\n", a + 2);
		else printf("%d\n", a + 1);
	}
	return 0;
}
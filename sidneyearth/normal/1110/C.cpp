#include <stdio.h>
int b[] = {0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main(){
	int q; scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		int a, k, ans; scanf("%d", &a);
		for(int j = 0; j < 27; j++)
			if(a >> j & 1) k = j + 1;
		if((1 << k) - 1 != a)
			ans = (1 << k) - 1;
		else
			ans = b[k];
		printf("%d\n", ans);
	}
	return 0;
}
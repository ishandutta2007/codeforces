#include <cstdio>

int getOddSG(int x){
	if (x < 4)
		return x & 1;
	else if (x & 1)
		return 0;
	else{
		int x1 = getOddSG(x - 1), x2 = getOddSG(x >> 1);
		return x1 && x2 ? 0 : x1 != 1 && x2 != 1 ? 1 : 2;
	}
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = 0;
	if (k & 1){//0 1 0 1 2 0 2
		for (int t, i = 0; i < n; ++i){
			scanf("%d", &t);
			ans ^= getOddSG(t);
		}
	}
	else{//0 1 2 0 1 0 
		for (int t, i = 0; i < n; ++i){
			scanf("%d", &t);
			ans ^= t > 2 ? t & 1 ^ 1 : t;
		}
	}
	puts(ans ? "Kevin" : "Nicky");
	return 0;
}
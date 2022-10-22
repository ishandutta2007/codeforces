#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int R, C;
int Rc[550], Cc[550];

int main(){
	scanf("%d %d", &R, &C);
	if (R == 1 && C == 1){
		puts("0");
		return 0;
	}
	if (R < C){ 
		for (int i=1; i<=R; i++) Rc[i] = i;
		for (int i=1; i<=C; i++) Cc[i] = R+i;
	}
	else{
		for (int i=1; i<=C; i++) Cc[i] = i;
		for (int i=1; i<=R; i++) Rc[i] = C+i;
	}
	for (int i=1; i<=R; i++){
		for (int j=1; j<=C; j++){
			printf("%d ", Rc[i] / __gcd(Rc[i], Cc[j]) * Cc[j]);
		}
		printf("\n");
	}
	return 0;
}
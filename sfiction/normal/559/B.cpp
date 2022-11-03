/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 559B
 */
/*
 * R=(S,|)a[a][a]=min([a1]+[a2], [a2]+[a1])
 */
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2E5 + 100;

char A[MAXN], B[MAXN];
char temp[MAXN];

void trans(char a[], int n){
	if (n & 1){
		return;
	}
	int m = n >> 1;
	trans(a, m);
	trans(a + m, m);
	strncpy(temp, a + m, m);
	a[m] = '\0';
	if (strcmp(a, temp) <= 0){
		a[m] = temp[0];
	}
	else{
		strncpy(a + m, a, m);
		strncpy(a, temp, m);
	}
}

int main(){
	scanf("%s%s", A, B);
	int n = strlen(A);
	trans(A, n);
	trans(B, n);
	puts(!strcmp(A, B) ? "YES" : "NO");
	
	return 0;
}
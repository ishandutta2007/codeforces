#include<bits/stdc++.h>
using namespace std;

#define N 200020

int a[N], b[N], c[N], x, y, z, query, L, R;
char s[N];

int main(){
	scanf("%s", s);
	int len = strlen(s);

	for(int i = 1; i <= len; i ++){
		a[i] = a[i-1] + (s[i-1] == 'x');
		b[i] = b[i-1] + (s[i-1] == 'y');
		c[i] = c[i-1] + (s[i-1] == 'z');
		///cout << a[i] << " " << b[i] << " " << c[i] << endl;
	}

	for(scanf("%d", &query); query --; ){
		scanf("%d %d", &L, &R);
		if(R - L <= 1){ puts("YES"); continue; }
		if( a[R] - a[L-1] < (R - L + 1) / 3 || a[R] - a[L-1] > (R - L + 1) / 3 + 1 ) { puts("NO"); continue; }
		if( b[R] - b[L-1] < (R - L + 1) / 3 || b[R] - b[L-1] > (R - L + 1) / 3 + 1 ) { puts("NO"); continue; }
		if( c[R] - c[L-1] < (R - L + 1) / 3 || c[R] - c[L-1] > (R - L + 1) / 3 + 1 ) { puts("NO"); continue; }
		puts("YES");
	}
}
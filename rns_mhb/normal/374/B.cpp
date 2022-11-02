#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000

char a[N];
int x, y, z;
ll p, q, r;

int main(){
	scanf("%s", a + 1);
	int len = strlen(a + 1), i;
	for(i = 1; i <= len; i++) a[i] -= '0';
	q = 1; p = 1;
	for(i = 2; i <= len; i++){
		r = 0;
		if(a[i] + a[i - 1] == 9){
			z = max(x + 1, y);
			if(z == y) r += q;
			if(z == x + 1) r += p;
		}
		else z = y, r = q;
		x = y; y = z;
		p = q; q = r;
	}
	cout << q << endl;
}
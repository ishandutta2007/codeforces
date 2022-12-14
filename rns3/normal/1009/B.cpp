#include <bits/stdc++.h>

using namespace std;



#define N 101010



char s[N];



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%s", s);

	int n = strlen(s);

	int one = 0;

	for (int i = 0; i < n; i ++) if (s[i] == '1') one ++;

	for (int i = 0; i < n; i ++) {

		if (s[i] == '0') printf("0");

		else if (s[i] == '2') {

			if (one > 0) while (one --) printf("1");

			printf("2");

		}

	}

	if (one > 0) while (one --) printf("1");

	puts("");



	return 0;

}
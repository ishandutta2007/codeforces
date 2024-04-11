#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 2000;
	cout<<n<<endl;
	for (int i = 1; i <= 1000; i ++) {
		printf("%d 1 %d 2\n", i, i);
	}
	for (int i = 1000; i; i --) {
		printf("%d 1 %d 2\n", i, i);
	}
}
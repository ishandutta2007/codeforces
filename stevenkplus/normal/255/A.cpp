#include <cstdio>
#include <iostream>

using namespace std;

string strs[] = {"chest", "biceps", "back"};

int N;
int ar[3];
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		ar[i % 3] += tmp;
	}
	int b = 0;
	for(int i = 0; i < 3; ++i) {
		if (ar[i] > ar[b]) {
			b = i;
		}
	}

	printf("%s\n", strs[b].c_str());

	return 0;
}
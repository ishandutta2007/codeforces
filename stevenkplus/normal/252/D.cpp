#include <cstdio>

using namespace std;

const int MAXN = 110;

int present[MAXN];
int masha[MAXN];

int cur[MAXN];
int tmp[MAXN];

int N, K;
void move() {
	for(int i = 0; i < N; ++i) {
		tmp[i] = cur[present[i]];
	}
	for(int i = 0; i < N; ++i) {
		cur[i] = tmp[i];
	}
}

bool eq() {
	for(int i = 0; i < N; ++i) {
		if (cur[i] != masha[i]) {
			return false;
		}
	}
	return true;
}
bool done() {
	for(int i = 0; i < N; ++i) {
		if (cur[i] != i) {
			return false;
		}
	}
	return true;
}

bool poss(int a, int b) {
	if (a < b) {
		return false;
	}
	return (a % 2 == b % 2);
}


int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		present[i] = tmp - 1;
	}
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		masha[i] = tmp - 1;
	}
	for(int i = 0; i < N; ++i) {
		cur[i] = i;
	}
	
	if (eq()) {
		printf("NO\n");
		return 0;
	}
	int a, b;
	for(a = 0; a <= K && !eq(); ++a) {
		move();
	}
	
	if (a == 0) {
		printf("NO\n");
	}
	
	for(int i = 0; i < N; ++i){
		cur[i] = masha[i];
	}
	
	for(b = 0; b <= K && !done(); ++b) {
		move();
	}
	if (a == 1 && b == 1 && K > 1) {
		printf("NO\n");
	} else if ((K >= a && K % 2 == a % 2) || (K >= b && K % 2 == b % 2)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
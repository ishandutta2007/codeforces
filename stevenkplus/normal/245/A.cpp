#include <cstdio>

using namespace std;

int aTot;
int aReach;
int bTot;
int bReach;

bool a() {
	return aReach * 2 >= aTot;
}
bool b() {
	return bReach * 2 >= bTot;
}

void read() {
	int x, r, t;
	scanf("%d %d %d", &x, &r, &t);
	switch(x) {
	case 1: aTot += r + t;
		aReach += r;
		break;
	case 2: bTot += r + t;
		bReach += r;
		break;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	aTot = aReach = bTot = bReach = 0;
	for(int i = 0; i < N; ++i) {
		read();
	}
	if (a()) {
		printf("LIVE\n");
	} else {
		printf("DEAD\n");
	}
	if (b()) {
		printf("LIVE\n");
	} else {
		printf("DEAD\n");
	}
	return 0;
}
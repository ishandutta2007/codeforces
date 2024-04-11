#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < 9; ++i) {
		printf("%d?0?<>%d0\n", i, i + 1);
	}
	printf("9?0?>>?0?0\n");
	printf("?0?<>10\n");
	for (int i = 0; i <= 9; ++i) {
		printf("?%d>>%d?\n", i, i);
	}
	for (int i = 0; i < 9; ++i) {
		printf("%d?<>%d\n", i, i + 1);
	}
	printf("9?>>?0?\n");
	
	for (int i = 0; i <= 9; ++i) {
		printf("%d>>?%d\n", i, i);
	}
	

	return 0;
}
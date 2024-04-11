#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;
char str[200000];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	vector<pair<int, int>> rle;
	int oneCount = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') {++oneCount; continue;}
		if (rle.empty()) rle.emplace_back(str[i], 1);
		else if (rle.back().first == str[i]) ++rle.back().second;
		else rle.emplace_back(str[i], 1);
	}
	if (rle.empty()) {printf("%s\n", str); return 0;}
	else if (rle[0].first == '2') {
		for (int i = 0; i < oneCount; ++i) printf("1");
		for (int i = 0; i < rle[0].second; ++i) printf("2");
	} else {
		for (int i = 0; i < rle[0].second; ++i) printf("0");
		for (int i = 0; i < oneCount; ++i) printf("1");
	}
	for (int j = 1; j < rle.size(); ++j) {
		for (int i = 0; i < rle[j].second; ++i) printf("%c", rle[j].first);
	}
	printf("\n");
	return 0;
}
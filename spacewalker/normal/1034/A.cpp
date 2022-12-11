#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
constexpr int NMAX = 15000010;

bool isPrime[NMAX];
int placeInVList[NMAX];
int occsInList[NMAX];

vector<int> prime;

void initPrimes() {
	for (int i = 0; i < NMAX; ++i) placeInVList[i] = -1;
	for (int i = 2; i < NMAX; ++i) isPrime[i] = true;
	for (int i = 2; i < NMAX; ++i) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int toMark = 2*i; toMark < NMAX; toMark += i) isPrime[toMark] = false;
		}
	}
}

vector<vector<int>> appValues;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	initPrimes();
	int n; scanf("%d", &n);
	vector<int> arr(n);
	int gcdAll = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		gcdAll = gcd(gcdAll, arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		arr[i] /= gcdAll;
		// printf("compressing %d\n", arr[i]);
		if (placeInVList[arr[i]] == -1) {
			placeInVList[arr[i]] = appValues.size();
			appValues.emplace_back();
		}
		// printf("here\n");
		// printf("assigned idx %d\n", placeInVList[arr[i]]);
		// printf("container has size %lu\n", appValues.size());
		appValues[placeInVList[arr[i]]].push_back(i);
	}
	// printf("done compressing\n");
	vector<vector<int>> primedivs(n);
	for (int i : prime) {
		for (int mult = i; mult < NMAX; mult += i) {
			if (placeInVList[mult] != -1) {
				for (int v : appValues[placeInVList[mult]]) {
					primedivs[v].push_back(i);
				}
			}
		}
	}
	// printf("done with bottleneck\n");
	for (int i = 0; i < n; ++i) {
		for (int prime : primedivs[i]) {
			occsInList[prime]++;
		}
	}
	int mostFreq = 0;
	for (int i = 0; i < NMAX; ++i) mostFreq = max(mostFreq, occsInList[i]);
	if (mostFreq == 0) printf("-1\n");
	else printf("%d\n", n - mostFreq);
	return 0;
}
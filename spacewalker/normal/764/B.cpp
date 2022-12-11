#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;


int main() {
	int n;
	scanf("%i", &n);
	vector<int> gifts(n, 0);
	vector<int> unscrambled(n, 0);
	int temp;
	for (int i = 0; i < n; ++i) {
		scanf("%i", &temp);
		gifts[i] = temp;
	}

	int leftEnd = 0;
	int rightEnd = n -1;
	bool reverse = false;
	while (leftEnd <= rightEnd) {
		int tLeft = (reverse? (n - leftEnd - 1) : leftEnd);
		int tRight = (reverse? (n - rightEnd - 1) : rightEnd);
		// reverse the interval from leftEnd to rightEnd
		reverse = !reverse;
		unscrambled[n-tLeft-1] = gifts[leftEnd];
		unscrambled[n-tRight-1] = gifts[rightEnd];
		// move forward
		++leftEnd; --rightEnd;
	}

	for (int i = 0; i < n; ++i) {
		printf("%i ", unscrambled[i]);
	}

	return 0;
}
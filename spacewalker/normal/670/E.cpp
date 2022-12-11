#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 500010;

char brackets[NMAX], ops[NMAX]; 

int main() {
	int n, m, initCursor; scanf("%d %d %d", &n, &m, &initCursor);
	vector<int> matched(n);
	vector<int> nextBracket(n, -1), prevBracket(n, -1);
	stack<int> unMatched;
	scanf("%s", brackets);
	scanf("%s", ops);
	for (int i = 0; i < n; ++i) {
		if (brackets[i] == '(') unMatched.push(i);
		else {
			int toMatch = unMatched.top(); unMatched.pop();
			matched[toMatch] = i;
			matched[i] = toMatch;
		}
	}
	for (int i = 0; i + 1 < n; ++i) nextBracket[i] = i + 1;
	for (int i = 1; i < n; ++i) prevBracket[i] = i - 1;
	int cCursor = initCursor - 1;
	int firstCharacter = 0;
	for (int i = 0; i < m; ++i) {
		if (ops[i] == 'L') cCursor = prevBracket[cCursor];
		else if (ops[i] == 'R') cCursor = nextBracket[cCursor];
		else { // fuck
			// delete the range
			int rangeDelStart = cCursor, rangeDelEnd = matched[cCursor];
			if (rangeDelEnd < rangeDelStart) swap(rangeDelEnd, rangeDelStart);
			// delete this entire range
			int toBridgeStart = prevBracket[rangeDelStart], toBridgeEnd = nextBracket[rangeDelEnd];
//			printf("first non-deleted %d %d\n", toBridgeStart, toBridgeEnd);
			cCursor = (toBridgeEnd != -1 ? toBridgeEnd : toBridgeStart);
			if (rangeDelStart == firstCharacter) firstCharacter = toBridgeEnd;
			if (toBridgeStart != -1) nextBracket[toBridgeStart] = toBridgeEnd;
			if (toBridgeEnd != -1) prevBracket[toBridgeEnd] = toBridgeStart;
		}
		/*
		printf("seq now %d %c\n", i, ops[i]);
		printf("cursor at %d\n", cCursor);
		for (int i = firstCharacter; i != -1; i = nextBracket[i]) printf("%c", brackets[i]);
		printf("\n");
		for (int i = 0; i < n; ++i) printf("%d ", prevBracket[i]);
		printf("\n");
		for (int i = 0; i < n; ++i) printf("%d ", nextBracket[i]);
		printf("\n");
		*/
	}
	for (int i = firstCharacter; i != -1; i = nextBracket[i]) printf("%c", brackets[i]);
	printf("\n");
	return 0;
}
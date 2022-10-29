#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

#define maxn 1000500
#define maxk 1048576
#define maxp 21
#define maxs 10001000

int sumTree[2 * maxk];
int wordBegin[maxn], wordEnd[maxn];
char s[maxs];
int n, row, col;
int numWords[maxn][maxp];

int init(const int &n, const int &shift) {
	for (int i = 0; i < 2 * shift; ++i)
		sumTree[i] = 0;
	return 0;
}

int addElem(const int &x, const int &shift, const int &val) {
	sumTree[x + shift - 1] += val;
	int par = (x + shift - 1) / 2;
	while (par)
		sumTree[par] += val, par /= 2;
	return 0;
}

int getSum(const int &l, const int &r, const int &shift) {
	int ll = l + shift - 1, rr = r + shift - 1;
	int sum = 0;
	while (ll < rr) {
		if (ll & 1) sum += sumTree[ll];
		if (!(rr & 1)) sum += sumTree[rr];
		ll = (ll + 1) / 2;
		rr = (rr - 1) / 2;
	}
	if (ll == rr) sum += sumTree[ll];
	return sum;
}

int getRightOne(const int &x, const int &shift) {
	int l = 0, r = n - x + 2;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (getSum(x, x + m - 1, shift) + m - 1 <= col)
			l = m;
		else
			r = m;
	}
	return l;
}

int makeTable(const int &n) {
	int curk = 2;
	while (curk < n) curk <<= 1;
	init(n, curk);
	for (int i = 0; i < maxp; ++i)
		numWords[n + 1][i] = 0;
	for (int i = 1; i <= n; ++i)
		addElem(i, curk, wordEnd[i] - wordBegin[i] + 1);
	for (int i = 1; i <= n; ++i)
		numWords[i][0] = getRightOne(i, curk);
	for (int pow = 1; pow < maxp; ++pow)
		for (int i = 1; i <= n; ++i)
			numWords[i][pow] = numWords[i + numWords[i][pow - 1]][pow - 1] + numWords[i][pow - 1];
	return 0;
}

int printString(const int &l, const int &r) {
	if (l < r) {
		s[wordEnd[r - 1] + 1] = 0;
		puts(s + wordBegin[l]);
	}
	return 0;
}

int getLen(const int &x) {
	int sumCol = 0, curLen = 0;
	int curx = x;
	for (int i = maxp - 1; i >= 0; --i) {
		if (sumCol + (1 << i) <= row) {
			curLen += numWords[curx][i];
			curx += numWords[curx][i];
			sumCol += (1 << i);
		}
	}
	return curLen;
}

int main() {
	scanf("%d%d%d\n", &n, &row, &col);
	gets(s);
	int len = strlen(s);
	bool isWord = false;
	int curBegin = 0;
	int cnt = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] != ' ') {
			if (!isWord) {
				isWord = true;
				curBegin = i;
			}
		} else {
			if (isWord) {
				isWord = false;
				wordBegin[++cnt] = curBegin;
				wordEnd[cnt] = i - 1;
			}
		}
	}
	if (isWord) {
		isWord = false;
		wordBegin[++cnt] = curBegin;
		wordEnd[cnt] = len - 1;
	}
	//assert(cnt == n);
	makeTable(n);
	int pos = 1, res = getLen(1);
	for (int i = 2; i <= n; ++i) {
		int tmp = getLen(i);
		if (tmp > res) {
			res = tmp;
			pos = i;
		}
	}
	int cur = pos;
	for (int i = 0; i < row && cur <= n; ++i) {
		printString(cur, cur + numWords[cur][0]);
		cur += numWords[cur][0];
	}
	return 0;
}
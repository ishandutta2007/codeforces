#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int L = 150;
const int B = 100000;
const int LB = 5;
class Long
{
public:
	int m[L], l;
	int &operator [](int i) { return m[i]; }
	Long operator =(char *s)
	{
		int i, j, n;
		for(n=0; s[n]>='0' && s[n]<='9'; n++);
		for(l=(n+LB-1)/LB, i=0; i<l; i++)
			for(m[i]=0, j=0; j<LB; j++)
				if(n-i*LB-LB+j>=0) m[i]=m[i]*10+s[n-i*LB-LB+j]-'0';
		return *this;
	}
	bool inp()
	{
		char s[L*LB+10];
		if(scanf("%s", s)==EOF) return 0;
		else { *this=s; return 1; }
	}
};

bool operator <(Long x, Long y)
{
	int i;
	if(x.l!=y.l) return x.l<y.l;
	for(i=x.l-1; i>=0 && x[i]==y[i]; i--);
	return i>=0 && x[i]<y[i];
}

Long operator /(Long x, int y)
{
	int i;
	long long h;
	for(h=0, i=x.l-1; i>=0; h=h*B+x[i], x[i]=h/y, h%=y, i--);
	for(; x.l>1 && !x[x.l-1]; x.l--);
	return x;
}
int operator %(Long x, int y)
{
	int i;
	long long h;
	for(h=0, i=x.l-1; i>=0; h=h*B+x[i], h%=y, i--);
	return h;
}

const int maxN = 2100;

int n;
Long a[maxN];

bitset < maxN > c[maxN], d[maxN];

void convert(Long a, bitset < maxN > &res) {
	int base = (1 << 30);
	vector < int > digits;

	Long zero;
	zero = "0";
	while (zero < a) {
		digits.push_back(a % base);
		a = a / base;
	}

	for (int i = 0; i < digits.size(); ++i) {
		for (int j = 0; j < 30; ++j) {
			if (digits[i] & (1 << j)) {
				res[i * 30 + j] = 1;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		a[i].inp();
		convert(a[i], c[i]);
		d[i][i] = 1;
	}

	const int maxL = 2000;
	vector < int > pos(maxL, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < maxL; ++j) {
			if (pos[j] != -1 && c[i][j]) {
				c[i] ^= c[pos[j]];
				d[i] ^= d[pos[j]];
			}
		}
		for (int j = 0; j < maxL; ++j) {
			if (pos[j] == -1 && c[i][j]) {
				pos[j] = i;
				break;
			}
		}
		int cnt = c[i].count();
		if (cnt == 0) {
			printf("%d", (int)(d[i].count()) - 1);
			for (int j = 0; j < i; ++j) {
				if (d[i][j]) {
					printf(" %d", j);
				}
			}
			printf("\n");
		} else {
			printf("0\n");
		}
	}


	return 0;
}
#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

char s[9];
int h, m, a;

int f(int i) {
	return s[i] - '0';
}

int main()
{
	scanf(" %s%d", s, &a);
	h = f(0)*10 + f(1);
	m = f(3)*10 + f(4);
	//printf("%d %d %d\n", h, m, a);
	m += a;
	h += m/60;
	m %= 60;
	h %= 24;
	printf("%02d:%02d\n", h, m);
}
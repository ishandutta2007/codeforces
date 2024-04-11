#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int a, b, c, d;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", std::max(std::abs(c-a), std::abs(d-b)));
}
#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int main()
{
	int N; scanf("%d", &N);
	for (int i = 30; i >= 0; i--) if (N & (1<<i)) printf("%d ", i+1);
	printf("\n");
}
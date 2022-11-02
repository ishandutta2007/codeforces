#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

std::vector<int> v, extra;
int N;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i += 2) v.pb(i);
	int s;
	if (N&1) {s = v.back()-2; extra.pb(v.back());}
	else s = v.back();
	for (int i = s; i >= 1; i-= 2) v.pb(i);
	for (int i = 2; i <= N; i += 2) v.pb(i);
	if (N&1) s = v.back();
	else {s=v.back()-2; extra.pb(v.back()); }
	for (int i = s; i >= 2; i -= 2) v.pb(i);
	for (int i : extra) v.pb(i);
	for (int i = 0; i < N+N; i++) printf("%d%c", v[i], " \n"[i == N+N-1]);
}
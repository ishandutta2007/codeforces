#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

i64 modpow(i64 a, i64 p)
{
	if (p == 0) return 1;
	if (p == 1) return a;
	i64 tmp = modpow(a, p / 2);
	tmp = (tmp * tmp) % MOD;
	if (p % 2) tmp = (tmp * a) % MOD;
	return tmp;
}

string S;
int N;
vector<string> qs;
char in[1001001];

i64 len[10], val[10];
// len : pow of 10

pair<i64, i64> parse(string &str)
{
	i64 lv = 1, rv = 0;
	for (int i = str.size() - 1; i >= 0 && str[i] != '>'; --i) {
		rv = (rv + lv * val[str[i] - '0']) % MOD;
		lv = (lv * len[str[i] - '0']) % MOD;
	}

	return make_pair(lv, rv);
}

int main()
{
	scanf("%s%d", in, &N);
	S = in;
	for (int i = 0; i < N; ++i) {
		scanf("%s", in);
		qs.push_back(string(in));
	}
	for (int i = 0; i < 10; ++i) {
		len[i] = 10;
		val[i] = i;
	}

	for (int i = N - 1; i >= 0; --i) {
		auto nv = parse(qs[i]);
		int t = qs[i][0] - '0';

		len[t] = nv.first;
		val[t] = nv.second;
	}

	cout << parse(S).second << endl;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility> 
using namespace std;
 
#define next fgdfvd
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int MOD = 1000000007;
const int MAX = 100000;
const int INF = 100000000;

int rev(int k){
	vector<int> a;

	while (k){
		a.PB(k % 2);
		k /= 2;
	}

	int res = 0;
	RFOR(i,a.size(),0)
		res = 2 * res + a[i]^1;

	return res;

}


int main()
{
	//freopen("in.txt", "r", stdin);

	LL N;
	cin >> N;
	LL res = N * (N + 1);

	int n = N;

	vector<int> a(n + 1);

	while (n >= 0){
		int k = rev(n);
		FOR(i,k,n + 1)
			a[i] = n + k - i;
		n = k - 1;
	}

	cout << res << endl;
	FOR(i,0,N + 1)
		cout << a[i] << ' ';

    return 0;
}
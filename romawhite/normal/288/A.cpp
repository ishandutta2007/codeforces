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


int main()
{
	//freopen("in.txt", "r", stdin);
	int n,k;
	cin >> n >> k;
	if (k > n){
		cout << -1 << endl;
		return 0;
	}

	if (k == 1){
		if (n == 1){
			cout << 'a' << endl;
		}
		else cout << -1 << endl;
		return 0;
	}

	string s;
	s.resize(n);
	FOR(i,0,n)
		s[i] = 'a' + i % 2;

	int j = k;

	RFOR(i,n,0)
		if (k == 2)
			break;
		else
		{
			s[i] = 'a' + k - 1;
			--k;
		}

	cout << s << endl;

    return 0;
}
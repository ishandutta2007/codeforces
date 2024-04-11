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

vector<int> a;

int n,k;

bool ok = 1;

void add(){
	int i = 0;
	while (i < a.size() && a[i] == k - 1) ++i;
	if (i == a.size()) ok = 0;
	else{
		a[i]++;
		FOR(j,0,i)
			a[j] = 0;
	}
}


int b[10];

int f(int v){
	if (b[v] != -1)
		return b[v];
	if (a[v - 1] == v) return b[v] = 0;
	b[v] = 0;
	return b[v] = f(a[v - 1]);
}

int main()
{
	//freopen("in.txt", "r", stdin);

	cin >> n >> k;

	a.resize(k - 1 , 0);
	int cnt = 0;
	while (ok){
		FILL(b , -1);
		b[0] = 1;

		FOR(i,0,k - 1)
			f(i + 1);

		bool q = 1;
		FOR(i,1,k)
			if (!b[i])
				q = 0;
		cnt += q;
		add();
	}
	LL res = 1;

	FOR(i,0,n - k)
		res = res * (n - k) % MOD;

	res = (res * (k)) % MOD;

	

	res = (res * cnt) % MOD;



	cout << res << endl;

    return 0;
}
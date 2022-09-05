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
typedef vector <int> VI;
typedef pair <int, int> PII;

int A[1007][1007];

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

	int t,sx,sy,ex,ey;
	cin >> t >> sx >> sy >> ex >> ey;
	int d = abs(sx - ex) + abs(sy - ey);
	if (d == 0){
		cout << 0 << endl;
		return 0;
	}

	string s;
	cin >> s;
	FOR(i,0,t){
		if (s[i] == 'E'){
			sx++;
			int dd = abs(sx - ex) + abs(sy - ey);
			if (dd < d)
				d = dd;
			else sx--;
		}

		if (s[i] == 'S'){
			sy--;
			int dd = abs(sx - ex) + abs(sy - ey);
			if (dd < d)
				d = dd;
			else sy++;
		}

		if (s[i] == 'W'){
			sx--;
			int dd = abs(sx - ex) + abs(sy - ey);
			if (dd < d)
				d = dd;
			else sx++;
		}

		if (s[i] == 'N'){
			sy++;
			int dd = abs(sx - ex) + abs(sy - ey);
			if (dd < d)
				d = dd;
			else sy--;
		}

		if (d == 0){
			cout << i + 1 << endl;
			return 0;
		}

	}
	cout << -1 << endl;
    return 0;
}
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
#include <time.h>
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
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200000;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n, d, h;
vector<PII> R;
int C[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    cin >> n >> d >> h;

    if (d == 1)
    {
    	if (n > 2)
    	{
    		cout << -1 << endl;
    		return 0;
    	}
    	cout << 1 << ' ' << 2 << endl;
    	return 0;
    }

    if (h < (d+1)/2)
    {
    	cout << -1 << endl;
    	return 0;
    }

    int cnt = 1, last = 0;
    FOR (i,0,h)
    {
    	R.PB(MP(last, cnt));
    	++ C[last];
    	++ C[cnt];
    	last = cnt;
    	++ cnt;
    }
    last = 0;
    FOR (i,0,d-h)
    {
    	R.PB(MP(last, cnt));
    	++ C[last];
    	++ C[cnt];
    	last = cnt;
    	++ cnt;
    }

    if (cnt > n)
    {
    	cout << -1 << endl;
    	return 0;
    }

    //FOR (i,0,cnt)
    	//cout << C[i] << endl;

    int v = -1;
    FOR (i,0,cnt)
    	if (C[i] > 1)
    		v = i;
    while (cnt < n)
    {
    	R.PB(MP(v, cnt));
    	++ cnt;
    }


    FOR (i,0,SZ(R))
    {
    	printf("%d %d\n", R[i].first+1, R[i].second+1);
    }




    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:160777216")
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
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
 
const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 7000;
const int MOD = 1000000007;
 
int t[4 * MAX];
int a[MAX];

int n;

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(2 * v + 1 , l, m);
	build(2 * v + 2, m + 1 , r);
	t[v] = t[2 * v + 1] + t[2 * v + 2];
}

void update(int v,int l, int r, int pos , int val)
{
	if (l == r)
	{
		t[v] += val;
		return;
	}
	int m = (l + r) / 2;
	if (pos <= m)
	{
		update(2 * v + 1 , l , m , pos , val);
	}
	else
	{
		update(2 * v + 2 , m + 1 , r, pos , val);
	}
	t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int sum(int v, int l, int r, int L , int R)
{
	if (L > R) return 0;
	if (l == L && r == R)
	{
		return t[v];
	}
	int m = (l + r) / 2;
	return sum(2 * v + 1 , l , m , L , min(R , m)) + sum(2 * v + 2 , m + 1 , r, max(L , m + 1) , R);
}

int main()
{
        #ifndef ONLINE_JUDGE
               // freopen("in.txt", "r", stdin);
        #endif
   
		//freopen("input.txt" , "r" , stdin);
		//freopen("output.txt" , "w", stdout);

		int n,q;
		cin >> n >> q;
		int L = 0;
		int R = n - 1;

		build(0,0,n - 1);

		FOR(i,0,q)
		{
			int t;
			scanf("%d" , &t);

			if (t == 1)
			{
				int p;
				scanf("%d" , &p);
				int len = max(R - L, L - R) + 1;
				if (p > len - p)
				{
					swap(L , R);
					p = len - p;
				}
				if (L <= R)
				{
					FOR(j,0,p)
					{
						update(0,0,n - 1, L + 2 * p - 1 - j, sum(0,0,n - 1, L + j, L + j));
					}
					L += p;
					/*cout << L << " * " << R << endl;
					FOR(j,L,R + 1)
					{
						cout << sum(0,0,n - 1, j,j) << ' ';
						
					}
					cout << endl;*/
				}
				else
				{
					FOR(j,0,p)
					{
						update(0,0,n - 1, L - 2 * p + 1 + j, sum(0,0,n - 1, L - j, L - j));
					}
					L -= p;
					/*cout << L << " * " << R << endl;
					RFOR(j,L + 1,R)
					{
						cout << sum(0,0,n - 1, j,j) << ' ';
						
					}
					cout << endl;*/
				}

				

			}
			else
			{
				int l, r;
				scanf("%d%d", &l, &r);
				if (L <= R)
				{
					printf("%d\n" , sum(0,0,n - 1, L + l, L + r - 1));
				}
				else
				{
					printf("%d\n" , sum(0,0,n - 1, L - r + 1, L - l));
				}
			}
		}

        return 0;
}
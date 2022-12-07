#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <memory.h>

#define ll long long
#define ld long double
#define ull unsigned ll
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(it,from,to) for(int (it)=from; (it)<to; (it)++)
const int  Inf = 1e9;
ll LINF = (ll)4e18;
const ll  mod = 1e9 + 7;
using namespace std;
#define M_PI       3.14159265358979323846   // pi
ll bb[12345678];
int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("cities.in", "r", stdin);
	//freopen("cities.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	int ans = Inf;
	for(int i=0; i<12345678; i++)
	{
	    bb[i]+=i;
	}
	if (pos >= l && pos <= r) {
		if (l == 1) {
			if (r == n) {
				ans = 0;
			}
			else {
				ans = abs(r - pos) + 1;
			}
		}
		else {
			if (r == n) {
				ans = abs(pos - l) + 1;
			}
			else {
				ans = min(pos - l, r - pos) + r - l + 2;
			}
		}
		
	}
	else {
		if (pos < l) {
			if (r == n) {
				ans = l - pos + 1;
			}
			else 
			ans = r - pos + 2;
		}
		else {
			if (l == 1) {
				ans = pos - r + 1;
			}
			else {
				ans = abs(l - pos) + 2;
			}
		}
	}
	cout << ans;
	return 0;
}
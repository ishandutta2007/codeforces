#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <sstream>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

#define ppb pop_back
#define pb push_back
#define mp make_pair
#define fs first
#define sd second

#define inf 1000000007
#define nmax 100010
#define mmax 100010
#define eps 1e-9

string s;
bool f1, f2, f3;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
	{
		f1 |= (s[i] >= 'a' && s[i] <= 'z');
		f2 |= (s[i] >= 'A' && s[i] <= 'Z');
		f3 |= (s[i] >= '0' && s[i] <= '9');
	}
	puts(f1 && f2 && f3 && s.size() >= 5 ? "Correct" : "Too weak");
	//while(1);
}
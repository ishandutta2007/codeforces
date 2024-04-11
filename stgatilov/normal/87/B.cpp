#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int n;
map<string, int> AllTypes;

int GetType(const string &s) {
	if (AllTypes.find(s) == AllTypes.end()) return -1;
	return AllTypes[s];
}

int Apply(int base, int addr, int fetch) {
	if (base < 0) return -1;
	int type = base + addr - fetch;
	if (type < 0) return -1;
	return type;
}

void PrintType(int t) {
	if (t < 0) printf("errtype\n");
	else {
		printf("void");
		for (int i = 0; i<t; i++) printf("*");
		printf("\n");
	}
}

char buff[1<<20];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	AllTypes[string("void")] = 0;
	gets(buff);
	sscanf(buff, "%d\n", &n);
	for (int i = 0; i<n; i++) {
		gets(buff);

		char *curr = strtok(buff, " ");
		bool def = (strcmp(curr, "typedef") == 0);

		curr = strtok(0, " ");
		int addr = 0;
		int fetch = 0;
		string base;
		for (int i = 0; curr[i]; i++) {
			if (curr[i] == '*') addr++;
			else if (curr[i] == '&') fetch++;
			else base += curr[i];
		}
		int type = Apply(GetType(base), addr, fetch);

		if (!def) {
			PrintType(type);
		}
		else {
			curr = strtok(0, " ");
			string name = curr;
			AllTypes[name] = type;
		}
	}
	return 0;
}
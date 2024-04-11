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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

int n;
vector<string> path;

char buff[1<<20];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

	gets(buff);
	sscanf(buff, "%d", &n);
	for (int i = 0; i<n; i++) {
		gets(buff);
		char *sptok = strtok(buff, " ");

		if (strcmp(sptok, "pwd") == 0) {
			for (int i = 0; i<path.size(); i++)
				printf("/%s", path[i].c_str());
			printf("/\n");
		}
		else {
			sptok = strtok(0, " ");
			if (sptok[0] == '/')
				path.clear();
			for (char *curr = strtok(sptok, "/"); curr; curr = strtok(0, "/")) {
				if (strcmp(curr, "..") == 0)
					path.pop_back();
				else
					path.push_back(curr);
			}
		}
	}

	return 0;
}
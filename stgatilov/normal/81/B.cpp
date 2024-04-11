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

int l;
char str[1024];
int pos;
string token;

bool isd(char c) {
	return c>='0' && c<='9';
}

void Next() {
	token = "";
	while (str[pos] == ' ') pos++;

	if (str[pos] == 0) {
		return;
	}
	if (str[pos] == ',') {
		token = ",";
		pos++;
		return;
	}
	if (str[pos] == '.') {
		token = "...";
		pos += 3;
		return;
	}

	int end;
	for (end = pos; isd(str[end]); end++)
		token += str[end];
	pos = end;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	gets(str);
	l = strlen(str);
	pos = 0;

	bool lastcomma = false;
	bool first = true;
	bool lastnum = false;
	while (1) {
		Next();
		if (!token.size()) break;
//		printf("[%s]\n", token.c_str());

		if (lastcomma || (token == "..." && !first) || (lastnum && isd(token[0])))
			printf(" ");
		printf("%s", token.c_str());

		first = false;
		lastcomma = (token == ",");
		lastnum = (isd(token[0]));
	}

	return 0;
}
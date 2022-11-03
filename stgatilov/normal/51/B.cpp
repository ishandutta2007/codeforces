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

string str;
int pos;
vector<int> ans;

string token;
void Next() {
	while (str[pos] != '<') pos++;
	int left = pos;
	while (str[pos] != '>') pos++;
	pos++;
	int right = pos;
	token = str.substr(left, right - left);
}

void ParseTable();

int ParseElem() {
	Next();
	if (token == "<table>") ParseTable();
	Next();
	return 1;
}

int ParseRow() {
	int res = 0;
	Next();
	while (token == "<td>") {
		res += ParseElem();
	}
	Next();
	return res;
}

void ParseTable() {
	int res = 0;
	Next();
	while (token == "<tr>") {
		res += ParseRow();
	}
	Next();
	ans.push_back(res);
}

char buff[65536];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	while (scanf("%s", buff) == 1) str += string(buff);
	str += "<omg>";

	pos = 0;
	Next();

	ParseTable();

	sort(ans.begin(), ans.end());
	for (int i = 0; i<ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
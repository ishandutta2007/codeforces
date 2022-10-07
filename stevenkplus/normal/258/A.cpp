#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 100100;

char buf[MAXN];
string str;
int main() {
	scanf("%s", buf);
	str = string(buf);
	int len = strlen(buf);
	int del = 0;
	for(int i = 0; i < len; ++i) {
		if (str[i] == '0') {
			del = i;
			break;
		}
	}
	str = str.substr(0, del) + str.substr(del + 1);
	printf("%s\n", str.c_str());
	return 0;
}
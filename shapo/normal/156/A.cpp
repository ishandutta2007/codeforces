#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxs 2500

using namespace std;

char s[maxs], u[maxs];
int res = 100500;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf(" %s %s", s, u);
	int len = strlen(s), lem = strlen(u);
	for(int i = 0; i < len; ++i){
		int j = i, cp = 0, sovp = 0;
		while(j < len && cp < lem){
			if(s[j] == u[cp])++sovp;
			++j; ++cp;
		}
		if(res > lem - sovp)res = lem - sovp;
	}
	for(int i = 0; i < lem; ++i){
		int j = i, cp = 0, sovp = 0;
		while(j < lem && cp < len){
			if(s[cp] == u[j])++sovp;
			++j; ++cp;
		}
		if(res > lem - sovp)res = lem - sovp;
	}
	printf("%d\n", res);
	
	return 0;
}
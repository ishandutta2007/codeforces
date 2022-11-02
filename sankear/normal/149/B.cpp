#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;

int lst[300];

inline int get(char ch){
	if(ch >= '0' && ch <= '9'){
		return ch - '0';
	}
	return ch - 'A' + 10;
}

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	string a = "", b = "";
	int i = 0;
	while(i < s.size() && s[i] != ':'){
		a += s[i++];
	}
	i++;
	while(i < s.size()){
		b += s[i++];
	}
	int sz = 0;
	for(int i = 2; i <= 200; i++){
		ll aa = 0, bb = 0;
		for(int j = 0; j < (int)a.size(); j++){
			int cur = get(a[j]);
			if(cur >= i){
				aa = 100;
				break;
			}
			aa = aa * i + cur;
		}
		for(int j = 0; j < (int)b.size(); j++){
			int cur = get(b[j]);
			if(cur >= i){
				bb = 100;
				break;
			}
			bb = bb * i + cur;
		}
		if(aa >= 0 && aa < 24 && bb >= 0 && bb < 60){
			lst[sz++] = i;
		}
	}
	if(sz == 0){
		printf("0\n");
		return 0;
	}
	if(sz > 100){
		printf("-1\n");
		return 0;
	}
	for(int i = 0; i < sz; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", lst[i]);
	}
	printf("\n");
	return 0;
}
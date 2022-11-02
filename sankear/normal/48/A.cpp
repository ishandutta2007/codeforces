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

bool can[10][10];
int t[10];

inline int f(string s){
	if(s == "rock"){
		return 0;
	}
	if(s == "paper"){
		return 1;
	}
	return 2;
}

inline string g(int a){
	if(a == 0){
		return "F";
	}
	if(a == 1){
		return "M";
	}
	return "S";
}

int main(){
	//freopen("balls.in", "r", stdin);
	//freopen("balls.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	can[0][2] = can[2][1] = can[1][0] = true;
	for(int i = 0; i < 3; i++){
		string s;
		cin >> s;
		t[i] = f(s);
	}
	int sz = 0, last;
	for(int i = 0; i < 3; i++){
		bool fl = true;
		for(int j = 0; j < 3; j++){
			if(i != j && !can[t[i]][t[j]]){
				fl = false;
				break;
			}
		}
		if(fl){
			sz++;
			last = i;
		}
	}
	if(sz != 1){
		printf("?\n");
		return 0;
	}
	cout << g(last) << endl;
	return 0;
}
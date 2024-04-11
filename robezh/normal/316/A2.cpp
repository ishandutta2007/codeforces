#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;

bool isNumber(char c){
	return c >= '0' && c <= '9';
}

bool isLetter(char c){
	return c >= 'A' && c <= 'J';
}

set<char> S;
int cntQ = 0;
char fst;

int main(){
	string str;
	getline(cin, str);
	for(int i = 0; i < str.length(); i++){
		if(isLetter(str[i])) S.insert(str[i]);
		if(str[i] == '?') cntQ ++;
	}
	if(S.size() > 10) return !printf("0");
	long long res = 1;
	int num0 = 0;
	for(int i = 0; i < S.size(); i++) res *= (10-i);
	for(int i = 0; i < cntQ; i++) num0 ++;
	if(isLetter(str[0]) || str[0] == '?'){
		if(num0 > 0) num0 --;
		else res /= 10;
		res *= 9;
	}
	
	cout << res;
	for(int i = 0; i < num0; i ++) cout << 0;
}
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int pre[100050];
int suf[100050];

bool upper(char c){
	return c >= 'A' && c <= 'Z';
}

int main(){
	string str;
	getline(cin, str);
	pre[0] = 0;
	for(int i = 1; i <= str.length(); i++){
		if(upper(str[i-1])) pre[i] = pre[i-1] + 1;
		else pre[i] = pre[i-1];
	}
	suf[str.length()] = 0;
	for(int i = str.length()-1; i >= 0; i--){
		if(upper(str[i])) suf[i] = suf[i+1];
		else suf[i] = suf[i+1] + 1;
	}
	int minRes = 1000000000;
	for(int i = 0; i <= str.length(); i++){
		minRes = min(minRes, (int)str.length() - pre[i] - suf[i]);
	}
	cout << minRes;
}
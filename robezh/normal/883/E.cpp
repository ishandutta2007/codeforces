#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

map<char, int> M;

int n;
int s;
bool existed[200];
bool unknown[55];
string word_str[1005];
string str;

bool check(char c){
	for(int i = 0; i < n; i++){
		bool exi = false;
		for(int j = 0; j < word_str[i].length(); j++){
			if((unknown[j] && existed[word_str[i][j]]) || (unknown[j] && word_str[i][j] == c) || (!unknown[j] && word_str[i][j] != str[j])){
				exi = true;
				break;
			}
		}
		if(!exi){
			return false;
		}
	}
	return true;
}

int main(){
	fill(existed, existed + 200, false);
	fill(unknown, unknown + 55, false);
	scanf("%d", &n);
	
	getchar();
	getline(cin, str);
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++){
		getline(cin, word_str[i]);
	}
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '*') unknown[i] = true;
		else existed[str[i]] = true;
	}
	int cnt = 0;
	for(int c = 'a'; c <= 'z'; c++){
		if(check(c)) cnt++;
	}
	cout << cnt;
}
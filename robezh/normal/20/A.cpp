#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string str;
vector<char> V;

int main(){
	char prev = 'k';
	getline(cin, str);
	
	if(str.length() == 1) return !printf("/");
	
	
	for(int i = 0; i < str.length(); i++){
		if(prev == '/' && str[i] == '/') continue;
		V.push_back(str[i]);
		prev = str[i];
	}
	int pos = 0;
	for(int i = V.size()-1; i >= 0; i--){
		if(V[i] != '/'){
			pos = i;
			break;
		}
	}
	for(int i = 0; i <= pos; i++) printf("%c", V[i]);
}
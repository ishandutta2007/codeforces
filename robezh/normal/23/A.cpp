#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> S;

int main(){
	string str;
	getline(cin, str);
	for(int len = str.length(); len >= 1; len--){
		for(int start = 0; start <= str.length() - len; start++){
			int size = S.size();
			S.insert(str.substr(start, len));
			if(S.size() == size) return !printf("%d\n", len);
		}
	}
	return !printf("0\n");
}
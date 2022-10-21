#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

char c[100005];
int n;
string str;

int main(){
	for(int i = 0; i < 100005; i++){
		c[i] = '0';
	}
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++){
		getline(cin, str);
		int len = str.length();
		for(int j = 0; j < len; j++){
			if(str[j] != '?'){
				if(c[j] == '0' || str[j] == c[j]) c[j] = str[j];
				else c[j] = '?';
			}
		}
	}
	for(int i = 0; i < str.length(); i++){
		printf("%c", c[i] == '0' ? 'x' : c[i]);
	}
}
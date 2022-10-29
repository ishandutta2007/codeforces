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
#include <string>

#define maxlen 20000
#define maxn 10
#define maxs 210

using namespace std;

int n, len;
char s[maxlen];
char opr[maxn], to_go[maxs];

int init(char *s, int &len){
	s[0] = '/'; len = 1; s[len] = 0;
	return 0;
}

int add(char *s, int &len, const char &x){
	s[len] = x; ++len; s[len] = 0;
	return 0;
}

int main(){
	scanf("%d", &n);
	init(s, len);
	for(int i = 1; i <= n; ++i){
		scanf(" %s", opr);
		if(opr[0] == 'c'){
			scanf(" %s", to_go);
			int go_len = strlen(to_go);
			int i = 0;
			if(to_go[i] == '/'){init(s, len); ++i;}
			while(i < go_len){
				if(to_go[i] == '.'){
					--len; s[len] = 0;
					while(s[len - 1] != '/'){--len; s[len] = 0;}
					i += 3;
				}
				else{
					while(i < go_len && to_go[i] != '/'){
						add(s, len, to_go[i]);
						++i;
					}
					++i;
					add(s, len, '/');
				}
			}
		}
		else printf("%s\n", s);
	}
	return 0;
}
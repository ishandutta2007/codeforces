#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		bool flag = 0;
		int cnt = 0;
		for(char *c = s; *c; c++){
			if(*c == '0'){
				if(!flag){
					flag = true;
					cnt++;
				}
			}else{
				flag = false;
			}
		}
		printf("%d\n", min(cnt, 2));
	}
}
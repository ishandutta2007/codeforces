#include<cstdio>
#include<iostream>
using namespace std;

int n,m;
char s[105];
int l,r;
char c1,c2;

int main(){
	scanf("%d%d", &n, &m);
	getchar();
	scanf("%s", s);
	for(int i = 0; i < m; i++){
		getchar();
		cin >> l >> r >> c1 >> c2;
		for(int j = l-1; j <= r-1; j++){
			if(s[j] == c1) s[j] = c2;
		}
	}
	
	printf("%s",s);
}
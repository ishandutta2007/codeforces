/*
ID: Sfiction
OJ: CF
PROB: 448B
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=100+10;

char s[MAXN],t[MAXN];

bool partof(char *a,char *b){
	for (;*a && *b;++a)
		if (*a==*b)
			++b;
	return !*b;
}

int main(){
	scanf("%s%s",s,t);
	if (partof(s,t))
		puts("automaton");
	else{
		sort(s,s+strlen(s));
		sort(t,t+strlen(t));
		if (partof(s,t))
			puts(strlen(s)==strlen(t) ? "array" : "both");
		else
			puts("need tree");
	}
	return 0;
}
// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[3][110],t[6]="aeiou";
	int n[3]={};
	for ( int i=0; i<3; i++ ) {
		gets(s[i]);
		for ( int j=0; j<5; j++ ) n[i]+=count(s[i],s[i]+strlen(s[i]),t[j]);
	}
	puts(n[0]==5 && n[1]==7 && n[2]==5 ? "YES" : "NO" );
	return 0;
}
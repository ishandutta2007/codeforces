// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
vector<string> v;
int main()
{
	string now;
	int i,j,n,m;
	char s[300];
	gets(s);
	n=strlen(s);
	for ( i=j=0; i<n; i=j ) {
		now="";
		if ( isdigit(s[i]) ) {
			for ( j=i; j<n && isdigit(s[j]); j++ ) now+=s[j];
		} else if ( s[i]==',' ) {
			j=i+1;
			now=",";
		} else if ( s[i]==' ' ) {
			j=i+1;
			continue;
		} else if ( s[i]=='.' ) {
			j=i+3;
			now="...";
		} else puts("QQ");
		v.push_back(now);
	}
	m=v.size();
	for ( i=0; i<m; i++ ) {
		if ( isdigit(v[i][0]) ) {
			if ( i>0 && isdigit(v[i-1][0]) ) putchar(' ');
			printf("%s",v[i].c_str());	
		} else if ( v[i]=="," ) {
			putchar(',');
			if ( i<m-1 ) putchar(' ');
		} else if ( v[i]=="..." ) {
			if ( i>0 && v[i-1]!="," ) putchar(' ');
			printf("...");
		}	
	}
	puts("");
	return 0;
}
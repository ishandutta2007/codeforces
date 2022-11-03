#include <bits/stdc++.h>
using namespace std;

char dya[]="AbdHIMOopqTUVvWwXxY";
char dyb[]="AdbHIMOoqpTUVvWwXxY";
char dy[255],s[1005];
int n;

int main(){
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<19;i++){
		dy[dya[i]]=dyb[i];
	}
	for(int i=0;i<n;i++){
		if(dy[s[i]]!=s[n-i-1]){
			puts("NIE");
			return 0;
		}
	}
	puts("TAK");
	return 0;
}
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
#define MAX_N 1000000000
string str;

int main(){
	while(1){
		cin>>str;
		if(str[0]=='e')	return 0;
		int t = 1;
		while(1){
			printf("? %d %d\n", t/2, t);
			fflush(stdout);
			cin>>str;
			if(str[0]=='x')	break;
			t*=2;
			if(t>=MAX_N)	break;
		}
		int s = t/2+1, e = min(t, MAX_N), m;
		t/=2;
		if(t==0){
			printf("! 1\n");
			fflush(stdout);
		}else if(t==1){
			printf("! 2\n");
			fflush(stdout);
		}
		else{
			while(s<e){
				m = (s+e)/2;
				printf("? %d %d\n", t, m);
				fflush(stdout);
				cin>>str;
				if(str[0]=='x')	e = m;
				else	s = m+1;
			}
			printf("! %d\n", s);
			fflush(stdout);
		}
	}
}
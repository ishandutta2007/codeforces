#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <time.h>

using namespace std;

int i=0,t=0;
char a[1111];

int main(){
	gets(a);
	while (i<strlen(a)){
		if (i+2<strlen(a)&&a[i]=='a'&&a[i+1]=='t'&&t==0&&i){
			t=1;
			putchar('@');
			i+=2;
		}else
		if (i+3<strlen(a)&&a[i]=='d'&&a[i+1]=='o'&&a[i+2]=='t'&&i){
			putchar('.');
			i+=3;
		}else putchar(a[i++]);
	}
	puts("");
	return 0;
}
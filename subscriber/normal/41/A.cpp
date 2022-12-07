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

char a[111],b[111];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	gets(a);
	gets(b);
	reverse(a,a+strlen(a));
	for (int i=0;i<strlen(a);i++)if (strlen(a)!=strlen(b)||a[i]!=b[i]){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
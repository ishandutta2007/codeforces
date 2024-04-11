#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n;
char a[11111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	for (int i=0;i<n;i++){
		gets(a);
		if (strlen(a)<11)puts(a);else{
			putchar(a[0]);
			cout << strlen(a)-2;
			putchar(a[strlen(a)-1]);
			puts("");
		}
	}
	return 0;
}
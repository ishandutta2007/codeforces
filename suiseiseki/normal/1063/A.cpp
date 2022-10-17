#include <cstdio>
#include <algorithm>
using namespace std;
char s[100005];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	sort(s+1,s+1+n);
	puts(s+1);
	return 0;
}
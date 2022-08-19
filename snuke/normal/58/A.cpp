#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,o,n) for(int i=o; i<n; i++)
#define drep(i,o,n) for(int i=o; i>n; i--)
#define pb push_back
using namespace std;

const char h[5] = {'h','e','l','l','o'};

int main () {
	int i = 0;
	char a[102];
	scanf("%s",a);
	for (int j = 0; j < strlen(a); j++) {
		if(a[j] == h[i]) i++;
		if (i == 5){puts("YES");return 0;}
	}
	puts("NO");
	return 0;	
}
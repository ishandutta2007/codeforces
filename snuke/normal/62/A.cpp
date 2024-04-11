#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iostream>
#include <sstream>
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,o,n) for(int i = o; i < n; i++)
#define drep(i,n) for(int i = n; i >= 0; i--)
#define pb push_back
typedef long long ll;
using namespace std;


int main () {
	int al, ar, bl, br;
	
	scanf("%d%d%d%d",&al,&ar,&bl,&br);
	
	if((bl <= ar*2 + 2 && ar <= bl + 1) || (br <= al*2 + 2 && al <= br + 1)) puts("YES\n"); else puts("NO\n");

	return 0;
}
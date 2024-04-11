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

int x,y,l;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> x >> y;
	l=(int)floor(sqrt(x*x+y*y)+1e-11);
	if (l*l==x*x+y*y||x==0||y==0)puts("black");else
	if (x*y>0){
		if (l%2==0)puts("black");else puts("white");
	}else{
		if (l%2)puts("black");else puts("white");
	};
	return 0;
}
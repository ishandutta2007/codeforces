#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int x1,x2,x3,Y1,y2,y3;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> x1 >> x2 >> x3 >> Y1 >> y2 >> y3;
	int f1=x1==Y1;
	int f2=x2==y2;
	int f3=x3==y3;
	if (f1+f2+f3>=1)puts("YES");else puts("NO");
	return 0;
}
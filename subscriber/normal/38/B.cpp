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

char x,xx;
int y,yy,ans=0,xi[8]={1,1,-1,-1,2,2,-2,-2},yi[8]={2,-2,2,-2,1,-1,1,-1};

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%c%d\n%c%d",&x,&y,&xx,&yy);
	x-='a';
	xx-='a';
	y--;
	yy--;
	for (int i=0;i<8;i++)for (int j=0;j<8;j++){
		if (i==x||j==y)continue;
		if (i==xx&&j==yy)continue;
		int t=0;
		for (int c=0;c<8;c++)if (i+xi[c]==x&&j+yi[c]==y)t=1;else
		if (i+xi[c]==xx&&j+yi[c]==yy)t=1;
		ans+=t^1;
	}
	cout << ans << endl;
	return 0;
}
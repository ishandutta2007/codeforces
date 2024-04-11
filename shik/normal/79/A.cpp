// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int x,y,flg=0;
	scanf("%d%d",&x,&y);
	while ( (x>=2&&y>=2) || (x>=1&&y>=12) || y>=22 ) {
		if ( flg==0 ) {
			if ( x>=2 && y>=2 ) x-=2,y-=2;
			else if ( x>=1 && y>=12 ) x-=1,y-=12;
			else y-=22;
		} else {
			if ( y>=22 ) y-=22;
			else if ( x>=1 && y>=12 ) x-=1,y-=12;
			else x-=2,y-=2;
		}
		flg^=1;	
	}
	puts(flg==0?"Hanako":"Ciel");
	return 0;
}
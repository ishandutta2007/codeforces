#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int xp,yp,xv,yv;
	scanf("%d%d%d%d", &xp,&yp,&xv,&yv);
	if (xp+yp <= max(xv,yv)) puts("Polycarp");
	else {
		if (xp-1 < xv && yp < yv || xp < xv && yp-1 < yv) puts("Polycarp");
		else puts("Vasiliy");
	}
	return 0;
}
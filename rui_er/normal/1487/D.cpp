//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;

/*
 * c=a^2-b
 * c^2=a^2+b^2
 * c^2-c=b^2+b
 * c^2-b^2=b+c
 * (b+c)(c-b)=b+c
 * Because b!=c
 * Therefore c=b+1
 * (*) <=> (a, b, c) : c=b+1
 * a^2+b^2=b^2+2b+1
 * a^2=2b+1
 * (2x-1, 2x^2-2x, 2x^2-2x+1)
 * (*) <=> 2x^2-2x+1<=n
 *     <=> 2x^2-2x+1-n<=0
 *     <=> a=2, b=-2, c=1-n
 *     <=> Delta=4-8(1-n)=8n-4>=0 (while n>=1)
 *     <=> x=(2(+/-)sqrt(8n-4))/4
 *     <=> x=(1(+/-)sqrt(2n-1))/2
 *     <=> x(positive)=(1+sqrt(2n-1))/2
 */
int n;

int main() {
	mulT0 {
		scanf("%d", &n);
		printf("%d\n", int(floor((1.0+sqrt(2.0*n-1.0))/2.0))-1);
	}
	return 0;
}
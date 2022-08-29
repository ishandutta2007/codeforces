#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int ax,bx,cx,ay,by,cy;
int main(){
	scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
	if((ax-bx)*1ll*(ax-bx)+(ay-by)*1ll*(ay-by)==(bx-cx)*1ll*(bx-cx)+(by-cy)*1ll*(by-cy)){
		bx-=ax;
		cx-=ax;
		by-=ay;
		cy-=ay;

		if(bx*1ll*cy!=cx*1ll*by)puts("Yes");
		else puts("No");
	}
	else puts("No");
	return 0;
}
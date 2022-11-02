#include<bits/stdc++.h>

#define inf 1000000001

using namespace std;

int n,m,x,y,k,i,a,b,dx,dy;

long long ans;

int main(){

	scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);

	while(k--){

		scanf("%d%d",&dx,&dy);

		if(dx>0){

			if(x+dx>n) continue;

			else a=(n-x)/dx;

		}

		else if(!dx) a=inf;

		else{

			if(x+dx<0) continue;

			else a=(x-1)/(-dx);

		}

		

		if(dy>0){

			if(y+dy>m) continue;

			else b=(m-y)/dy;

		}

		else if(!dy) b=inf;

		else{

			if(y+dy<0) continue;

			else b=(y-1)/(-dy);

		}

		

		ans+=min(a,b);

		x+=min(a,b)*dx,y+=min(a,b)*dy;

	}

	printf("%I64d\n",ans);

	return 0;

}
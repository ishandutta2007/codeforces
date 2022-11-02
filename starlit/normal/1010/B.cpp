#include<bits/stdc++.h>
#define N 33
using namespace std;
int m,n,l,r,mid,x;
bool p[N];
inline void fls(int v){
	printf("%d\n",v);
	fflush(stdout),scanf("%d",&x);
	if(!x)exit(0);
}
int main(){
	scanf("%d%d",&m,&n),l=2,r=m;
	for(int i=0;i<n;i++)
	fls(1),p[i]=x==1;
	for(int i=0;l<=r;i++){
		mid=l+r>>1;
		if(i==n)i=0;
		fls(mid);
		if(!p[i])x=-x;
		if(x<0)r=mid-1;else l=mid+1;
	}
}
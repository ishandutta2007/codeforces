#include<iostream>
#include<cstdio>
#include<cstring>
#define fls fflush(stdout)
using namespace std;
int n,sl,sr,xl,xr,mid;
bool le,now;
inline void qry(int x){
	printf("? %d\n",x);
	fls;scanf("%d",&xl);
	printf("? %d\n",(x+n/2-1)%n+1);
	fls;scanf("%d",&xr);
	if(xl==xr){
		printf("! %d\n",x),fls;
		exit(0);
	}
	now=xl>xr;
}
int main(){
	scanf("%d",&n);
	qry(1);sl=2,sr=n/2,le=now;
	for(;sl<=sr;){
		mid=sl+sr>>1;
		qry(mid);
		if(le^now)sr=mid-1;
		else sl=mid+1,le=now;
	}
	puts("! -1");fls;
}
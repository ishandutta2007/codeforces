#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int h,m,s,t1,t2;
int main(){
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	int p1=(h%12)*3600+m*60+s;
	int p2=m*720+s*12;
	int p3=s*720;

	t1=(t1%12)*3600;
	t2=(t2%12)*3600;
	int C=12*3600;
	int x=t1;
	while(x!=t2){
		if(x==p1)break;
		if(x==p2)break;
		if(x==p3)break;
		x=(x+1)%C;
	}
	if(x==t2){
		puts("YES");
		return 0;
	}
	x=t1;
	while(x!=t2){
		if(x==p1)break;
		if(x==p2)break;
		if(x==p3)break;
		x=(x+C-1)%C;
	}
	if(x==t2){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}
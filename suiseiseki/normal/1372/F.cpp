#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=200000;
int n;
int a[Maxn+5];
pair<int,int> ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	return make_pair(x,y);
}
void solve(int l,int r){
	if(l>r){
		return;
	}
	pair<int,int> u=ask(l,r);
	int mid=(l+r)>>1;
	int l_m=mid,r_m=mid+1;
	if(r-u.second+1<=l+u.second-1){
		for(int i=r-u.second+1;i<=l+u.second-1;i++){
			a[i]=u.first;
		}
		l_m=r-u.second;
		r_m=l+u.second;
	}
	solve(l,l_m);
	solve(r_m,r);
}
int main(){
	scanf("%d",&n);
	solve(1,n);
	printf("! ");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	fflush(stdout);
	return 0;
}
#include <cstdio>
#include <algorithm>
using std::exit;
int n;
int getid(int x){
	return (x+(n>>1)-1)%n+1;
}
int query(int x){
	printf("? %d\n? %d\n",x,getid(x));
	int a,b;
	fflush(stdout);
	scanf("%d%d",&a,&b);
	if(a==b){
		printf("! %d\n",x);
		exit(0);
	}
	return a-b;
}
int main(){
	scanf("%d",&n);
	if(n%4==2){
		puts("! -1");
		return 0;
	}
	int left=1,right=getid(1),mid;
	int num_l,num_r,num_m;
	num_l=query(left);
	num_r=-num_l;
	while(left+1<right){
		mid=(left+right)>>1;
		num_m=query(mid);
		if(num_l<0){
			if(num_m<0){
				left=mid;
			}
			else{
				right=mid;
			}
		}
		if(num_r<0){
			if(num_m<0){
				right=mid;
			}
			else{
				left=mid;
			}
		}
	}
	query(left);
	query(right);
	return 0;
}
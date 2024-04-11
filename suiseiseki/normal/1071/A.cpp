#include <vector>
#include <cstdio>
int n;
int a,b;
std::vector<int> lis_1,lis_2;
int main(){
	scanf("%d%d",&a,&b);
	int sum=0;
	for(n=1;(sum+=n)<=(a+b);n++);
	sum-=n;
	n--;
	for(int i=n;i>0;i--){
		if(a-i>=0){
			lis_1.push_back(i);
			a-=i;
		}
		else{
			lis_2.push_back(i);
			b-=i;
		}
	}
	printf("%d\n",(int)lis_1.size());
	for(int i:lis_1){
		printf("%d ",i);
	}
	puts("");
	printf("%d\n",(int)lis_2.size());
	for(int i:lis_2){
		printf("%d ",i);
	}
	puts("");
	return 0;
}
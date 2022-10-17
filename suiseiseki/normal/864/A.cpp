#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	if(n&1){
		puts("NO");
		return 0;
	}
	int the_one,the_two=-1<<30,a,sum_one=1,sum_two=0;
	scanf("%d",&the_one);
	for(int i=1;i<n;i++){
		scanf("%d",&a);
		if(a!=the_one){
			if(the_two==-1<<30||a==the_two){
				the_two=a;
			}
			else{
				puts("NO");
				return 0;
			}
			sum_two++;
		}
		else{
			sum_one++;
		}
	}
	if(sum_one!=sum_two){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d %d\n",the_one,the_two);
	return 0;
}
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int n;
	int left,right,mid;
	scanf("%d",&n);
	puts("0 1");
	left=1,right=1000000000;
	string s,ns;
	cin>>s;
	for(int i=1;i<n;i++){
		mid=(left+right)>>1;
		printf("%d 1\n",mid);
		cin>>ns;
		if(s==ns){
			left=mid;
		}
		else{
			right=mid;
		}
	}
	printf("%d 0 %d 2\n",left,right);
	return 0;
}
////
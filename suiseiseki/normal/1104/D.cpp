#include <cstdio>
#include <iostream>
using namespace std;
char qu[10];
int main(){
	fflush(stdout);
	scanf("%s",qu);
	int left,right,mid;
	int now;
	while((*qu)!='e'){
		cout<<"? 0 1"<<endl;
		scanf("%s",qu);
		if((*qu)=='x'){
			cout<<"! 1"<<endl;
			scanf("%s",qu);
			continue;
		}
		left=1;
		do{
			cout<<"? "<<left<<" "<<(left<<1)<<endl;
			scanf("%s",qu);
			left<<=1;
		}while((*qu)=='y');
		left>>=1;
		right=left<<1;
		now=left;
		left++;
		while(left<right){
			mid=(left+right)>>1;
			cout<<"? "<<now<<" "<<mid<<endl;
			scanf("%s",qu);
			if((*qu)=='x'){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		cout<<"! "<<left<<endl;
		scanf("%s",qu);
	}
	return 0;
}
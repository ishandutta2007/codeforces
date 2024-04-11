#include <ctime>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=1000;
int n,k;
char s[15];
int ask(int l_1,int r_1,int l_2,int r_2){
	cout<<"? "<<(r_1-l_1+1)<<' '<<(r_2-l_2+1)<<endl;
	for(int i=l_1;i<=r_1;i++){
		cout<<i<<' ';
	}
	cout<<endl;
	for(int i=l_2;i<=r_2;i++){
		cout<<i<<' ';
	}
	cout<<endl;
	cin>>s;
	if((*s)=='W'){
		exit(0);
	}
	if((*s)=='F'){
		return 1;
	}
	if((*s)=='S'){
		return -1;
	}
	if((*s)=='E'){
		return 0;
	}
}
int main(){
	srand(time(NULL));
	fflush(stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		int now=30;
		bool flag=0;
		while(now--){
			int x=2+rand()%(n-1);
			int ans=ask(1,1,x,x);
			if(ans==-1){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"! 1"<<endl;
			continue;
		}
		int left,right;
		for(int i=1,j=2,l=1;;j+=l,l<<=1){
			if(j+l-1>=n){
				int len=n-j+1;
				int ans=ask(i,i+len-1,j,j+len-1);
				if(ans==1){
					left=j,right=j+len-1;
					break;
				}
				break;
			}
			int ans=ask(i,i+l-1,j,j+l-1);
			if(ans==1){
				left=j;
				right=j+l-1;
				break;
			}
		}
		while(left<right){
			int mid=(left+right)>>1;
			if(ask(1,1+(mid-left+1)-1,left,mid)==1){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		cout<<"! "<<left<<endl;
	}
	return 0;
}
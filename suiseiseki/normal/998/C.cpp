#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 300000
#define ll long long
int a[Maxn+5];
int main(){
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	bool all_one=1;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		all_one=(all_one&&a[i]);
	}
	if(all_one){
		puts("0");
		return 0;
	}
	int num=0;
	int begin,end;
	if(x<=y){
		begin=1;
		end=n;
		while(a[begin]==1){
			begin++;
		}
		while(a[end]==1){
			end--;
		}
		for(int i=begin;i<=end;i++){
			if(a[i-1]==0&&a[i]==1){
				num++;
			}
		}
		if(num==0){
			printf("%d\n",y);
		}
		else{
			cout<<(ll)x*num+y<<endl;
		}
	}
	else{
		a[0]=1;
		for(int i=1;i<=n;i++){
			if(a[i-1]==1&&a[i]==0){
				num++;
			}
		}
		cout<<(ll)y*num<<endl;
	}
	return 0;
}
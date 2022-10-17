#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	long long left,right;
	if(n<k){
		left=k-n;
		if(left>=n){
			puts("0");
		}
		else{
			cout<<(n-left+1)/2<<endl;
		}
	}
	else{
		right=k-1;
		cout<<right/2<<endl;
	}
	return 0;
}
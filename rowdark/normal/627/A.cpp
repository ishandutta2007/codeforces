#include<stdio.h>
#include<iostream>
using namespace std;
long long dp[2][2];
int main(){
	long long s,x;
	cin>>s>>x;
	long long sub=0;
	if(s==x) sub=2;
	dp[0][0]=1;
	int n1=0,n2=1;
	for(int i=0;i<60;++i){
		for(int a=0;a<2;++a) for(int b=0;b<2;++b) if((a^b)==(x&1)){
			for(int c=0;c<2;++c){
				if(((a+b+c)&1)==(s&1)){
					dp[n2][a+b+c>=2]+=dp[n1][c];
				}
			}
		}
		dp[n1][0]=dp[n1][1]=0;
		n1^=1,n2^=1;
		x>>=1,s>>=1;
	}
	cout<<(dp[n1][0]-sub)<<endl;
	return 0;
}
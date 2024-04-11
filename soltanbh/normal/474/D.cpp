#include<iostream>
using namespace std;
long long l[200009],dp[200009],e=1e9+7;
int f(int x,int y){
	int ans;
	ans=dp[x];
	if(y>=0)
		ans+=dp[y];
	ans=ans%e;
	return ans;
}
int main(){
	int t,k,x,y;cin>>t>>k;dp[0]=1,l[0]=1;
	for(int i=1;i<100009;i++) {
	dp[i]=f(i-1,i-k);
	l[i]=(l[i-1]+dp[i])%e; }
	for(int i=0;i<t;i++){
		cin>>x>>y;
		cout<<((l[y]+e)-l[x-1])%e<<endl;
	}
}
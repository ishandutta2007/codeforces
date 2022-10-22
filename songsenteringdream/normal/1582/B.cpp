#include<iostream>
using namespace std;
int T,n,c,a;long long ans=1;
int main(){
	for(cin>>T;T--;cout<<ans*c<<endl,ans=1,c=0) for(cin>>n;n--;c+=(a==1),ans=(a?ans:(ans*2))) cin>>a;
	return 0;
}
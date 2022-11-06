#include<iostream>
using namespace std;
typedef long long LL;
long long a,b,c;
int T;
int main(){
	cin>>T;
	while(T--){
	cin>>a>>b;
	c=0;
	for(LL i=1LL<<62;i;i>>=1){
		if((a&i)!=(b&i)){
			if((b&(i-1))==i-1){
				c=b;
				break;
			}
			else{
				c+=i-1;
				break;
			}
		}
		else c+=a&i;
	}
	cout<<c<<endl;
	}
	return 0;
}
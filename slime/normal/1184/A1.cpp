#include<bits/stdc++.h>

using namespace std;

long long r;

int main(){
	cin>>r;
	for(long long i=1;i<=sqrt(r);i++){
		if((r-1ll*i*i-i-1)%(2*i)==0&&(r-1ll*i*i-i-1)/(2*i)>0){
			cout<<i<<' '<<(r-1ll*i*i-i-1)/(2*i)<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
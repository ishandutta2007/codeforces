#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	long long l,r;
	while(cin>>l>>r){
		puts("YES");
		for(long long i=l;i<=r;i+=2){
			cout<<i<<" "<<i+1<<endl;
		}
	}
	return 0;
}
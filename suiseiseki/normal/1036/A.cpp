#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	if(n>k){
		puts("1");
		return 0;
	}
	cout<<(k+n-1)/n<<endl;
	return 0;
}
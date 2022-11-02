#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	for(int i=2;;i++)
	if(n%i==0){
		printf("%d%d",i,n/i);
		return 0;
	}
}
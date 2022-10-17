#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int a[30];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,k,ans=(1<<30);
	string s;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		a[s[i]-'A']++;
	}
	for(int i=0;i<k;i++){
		ans=mn(ans,a[i]);
	}
	cout<<ans*k<<endl;
	return 0;
}
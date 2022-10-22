#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		if(n==1) cout <<"a\n";
		else 
			cout<<string(n/2,'a')+(n&1?"bc":"b")+string(n/2-1,'a')<<"\n";
	}
}
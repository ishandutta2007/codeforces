#include<bits/stdc++.h>

using namespace std;
using nagai=long long;

int main(){
	int t;
	cin>>t;
	while(t--){
		 int L,v,l,r;
		 cin>>L>>v>>l>>r;
		 int ll=(l+v-1)/v*v;
		 int rr=r/v*v;
		 if(ll>rr){
			 cout<<L/v<<'\n';
		 }
		 else
			 cout<<L/v-(rr/v-ll/v+1)<<'\n';
	}
}
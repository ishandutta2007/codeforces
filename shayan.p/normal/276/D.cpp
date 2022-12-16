#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll l,r;cin>>l>>r;
	ll last=0;
	ll tw=1;
	while(r>0){
		tw*=2;
		if(l%2!=r%2)last=tw-1;
		r/=2;
		l/=2;
	}
	cout<<last;
}
#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main(){
    cin>>T;
	while(T--){
		cin>>a>>b>>c;
		cout<<max(0,c-max(-1,(b+c-a)>>1))<<endl;
	}
}
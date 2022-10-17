#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
	int w1,h1,w2,h2;
	scanf("%d%d%d%d",&w2,&h2,&w1,&h1);
	ll ans=0;
	ans+=w1;
	ans+=h1;
	ans+=h1;
	ans+=w2;
	ans+=h2;
	ans+=h2;
	if(w1==w2){
		ans+=4;
	}
	else{
		ans+=w2-(w1+1);
		ans+=5;
	}
	cout<<ans<<endl;
	return 0;
}
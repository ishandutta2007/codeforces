#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	bool good = false;
	long long l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	for(int i = x; i <= y; i++){
		if(i * k <= r && i *k >= l){
			good = true;
			break;
		}
	}
	if(good) printf("YES");
	else printf("NO");
}
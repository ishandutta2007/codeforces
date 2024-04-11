#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,flag;
LL a;
string st;
int main(){
	cin>>a;
	LL st=0;
	for(LL i=2;i*i<=a;++i){
		if(a%i==0){
			if(i==2){st+=a/2;a=1;break;}
			st++;
			a-=i;
			i=1;
		}
	}
	if(a!=1)st++;
	printf("%lld\n",st);
	return 0;
}
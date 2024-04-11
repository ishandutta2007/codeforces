#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	INT n;INT k;
	scanf("%I64d%I64d",&n,&k);
	if(k>pow(2,n-1)) k=pow(2,n)-k;
	int t=0;
	while(1){
		t++;
		if(k%2) {cout<<t<<endl;return 0;}
		k/=2;
	}
	return 0;
}
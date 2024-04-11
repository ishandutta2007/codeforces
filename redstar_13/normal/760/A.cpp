#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int 
main(){
#ifndef ONLINE_JUDGE
	freopen("c.txt","r",stdin);
#endif
	int n,m,i;
	cin>>n>>m;
	int k=7-m+1;
	for(i=2;;i++){
		k+=7;
		if(p[n-1]-k<=7){
			if(p[n-1]-k==0)break;
			k+=p[n-1]-k;
			i++;
			break;
		}
	}
	cout<<i<<endl;
}
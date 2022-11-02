#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int f(INT n){
	int sum=0;
	while(n!=0){ sum+=n%10,n/=10;}
	return sum;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("d.txt","r",stdin);
#endif
	INT n;
	cin>>n;
	int t=sqrt(n);
	for(INT i=t-100;i<=t+100;i++){
		if(i<=0) continue;
		if(i*(i+f(i))==n){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}
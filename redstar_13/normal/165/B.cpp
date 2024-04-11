#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("a.txt","r",stdin);
#endif
	int n,k,i;
	scanf("%d%d",&n,&k);
	if(n<=k) {
		cout<<n<<endl;
		return 0;
	}
	int st=0,ed=1000000000;
	for(i=0;i<100;i++){
		int md=(st+ed)/2;
		int p=md;
		int s=0;
		while(p!=0){
			s+=p;
			p/=k;
		}
		if(s>=n) ed=md;
		else st=md;
	}
	cout<<ed;
}
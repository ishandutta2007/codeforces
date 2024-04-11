#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	INT a,b;
	cin>>a>>b;
	INT s=1;
	if(b-a>=10) s=0;
	else {
		b%=10;
		a%=10;
		if(b<a) s=0;
		else for(int i=a+1;i<=b;i++) s*=i;
	}
	cout<<s%10<<endl;
	return 0;
}
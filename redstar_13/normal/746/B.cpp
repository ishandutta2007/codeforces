#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char a[2020],s[2020];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	cin>>a+1;
	if(n%2) {
		s[n/2+1]=a[1];
		for(int i=2;i<=n;i+=2){
			s[n/2+1-i/2]=a[i];
			s[n/2+1+i/2]=a[i+1];
		}
	}
	else {
		for(int i=1;i<=n;i+=2){
			s[n/2-i/2]=a[i];
			s[n/2+1+i/2]=a[i+1];
		}
	}
	for(int i=1;i<=n;i++) cout<<s[i];
	return 0;
}
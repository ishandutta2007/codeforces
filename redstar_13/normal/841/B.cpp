#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
#define NN 1000100
int a[NN];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	INT s=0;
	int f=0;
	for(int i=1;i<=n;i++) {scanf("%d",a+i);s+=a[i];if(a[i]%2) f=1;}
	if(s%2) {printf("First");return 0;}
	else {
		if(f) {printf("First");return 0;}
		else {printf("Second");return 0;}
	}
	return 0;
}
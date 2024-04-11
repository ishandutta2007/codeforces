#include<bits/stdc++.h>
using namespace std;
char a[110];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	cin>>a+1;
	int len=strlen(a+1);
	int k=0;
	for(int i=1;i<=len/2;i++){
		if(a[i]!=a[len+1-i]) k++;
	}
	if(k==1 or (len%2 and k==0)) puts("YES");
	else printf("NO");
	return 0;
}
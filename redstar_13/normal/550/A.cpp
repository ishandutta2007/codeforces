#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char a[100100],b[110100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>a;
	int n=strlen(a);
	for(int i=0;i<=n-1;i++) b[i]=a[i];
	int f=0;
	for(int i=0;i<n-1;i++){
		if(a[i]=='A' and a[i+1]=='B') {f++;a[i]='o';a[i+1]='o';break;}
	}
	for(int i=0;i<n-1;i++){
		if(a[i]=='B' and a[i+1]=='A') {f++;a[i]='o';a[i+1]='o';break;}
	}
	int t=0;
	for(int i=0;i<n-1;i++){
		if(b[i]=='B' and b[i+1]=='A') {t++;b[i]='o';b[i+1]='o';break;}
	}
	for(int i=0;i<n-1;i++){
		if(b[i]=='A' and b[i+1]=='B') {t++;b[i]='o';b[i+1]='o';break;}
	}
	if(f==2 or t==2) printf("YES");
	else printf("NO");
	return 0;
}
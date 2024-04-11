#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
#define NN 10000010
int f[NN];
int R[10];
int sc(int t){
	int s=0;
	while(t){
		s++;
		R[s]=t%10;
		t/=10;
	}
	int e=R[1],r,w=1;
	for(int i=1;i<=s;i++){
		if(w==1 and R[i]!=e) r=R[i],w=2;
		if(w==2 and R[i]!=e and R[i]!=r) {w=8;break;}
	}
	return w;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	f[1]=99;
	for(int i=2;i<NN;i++){
		f[i]=f[i-1];
		int t=i-1;
		if(sc(t)==1) f[i]+=28;
		if(sc(t)==2) f[i]+=4;
	}
	int n;
	scanf("%d",&n);
	int s=f[n/100];
	int m;
	if(n<100) m=1;
	else m=(n/100)*100;
	for(int i=m;i<=n;i++) if(sc(i)==1 or sc(i)==2) s++;
	cout<<s;
	return 0;
}
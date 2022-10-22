#include<bits/stdc++.h>
using namespace std;
#define MN 100005
char A[MN],B[MN];
int n,m,q;
int preA[MN],preB[MN],sumA[MN],sumB[MN];
bool chk(int a,int b,int c,int d){
	int suf1=min(preA[b],b-a+1),suf2=min(preB[d],d-c+1);;
	if(suf1<suf2)return 0;
	int sum1=sumA[b]-sumA[a-1],sum2=sumB[d]-sumB[c-1];
	if(!sum1&&sum2&&suf1==suf2)return 0;
	if(sum1>sum2)return 0;
	if(sum1%2!=sum2%2)return 0;
	int _d=(suf1-suf2)%3>0;
//	cerr<<"? !"<<" "<<_d<<endl;
	if(sum1+_d*2<=sum2) return 1;
	return 0;
}
int main(){
	scanf("%s%s",A+1,B+1);
	n=strlen(A+1);m=strlen(B+1);
	for(int i=1;i<=n;++i)if(A[i]=='C')A[i]='B';
	for(int i=1;i<=n;++i){
		sumA[i]=sumA[i-1]+(A[i]=='B');
		if(A[i]=='A')preA[i]=preA[i-1]+1;
		else preA[i]=0;
	}

	for(int i=1;i<=m;++i)if(B[i]=='C')B[i]='B';
	for(int i=1;i<=m;++i){
		sumB[i]=sumB[i-1]+(B[i]=='B');
		if(B[i]=='A')preB[i]=preB[i-1]+1;
		else preB[i]=0;
	}
	
	scanf("%d",&q);
	while(q--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(q==-1){
			cerr<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			for(int i=a;i<=b;++i)cout<<A[i];cout<<endl;
			for(int i=c;i<=d;++i)cout<<B[i];cout<<endl;

		}
		putchar('0'+chk(a,b,c,d));
	}
	return 0;
}
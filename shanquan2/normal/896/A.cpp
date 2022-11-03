#include<bits/stdc++.h>
using namespace std;
const long long inf=(long long)(1e18)+5;
const char a[1005]="What are you doing at the end of the world? Are you busy? Will you save us?",b[1005]="What are you doing while sending \"*\"? Are you busy? Will you send \"*\"?";

int n,m,l,c1,c2;
long long k,len[100005];
char gao(int n,long long k){
	if(k>len[n])return '.';
	if(n==0)return a[k-1];
	if(k<c1)return b[k-1];
	if(k>=c1&&k<=c1+len[n-1]-1)return gao(n-1,k-c1+1);
	if(k>=c1+len[n-1]&&k<c2-1+len[n-1])return b[k-len[n-1]];
	if(k>=c2-1+len[n-1]&&k<=c2-2+2*len[n-1])return gao(n-1,k-(c2-1+len[n-1])+1);
	return b[k-len[n-1]*2+1];
}
int main(){
	int T;scanf("%d",&T);
	m=strlen(a),l=strlen(b);
	len[0]=m;bool f=1;
	for(int i=1;i<100005;i++){
		len[i]=len[i-1]*2+l-2;
		if(!f)len[i]=len[i-1];
		if(len[i]>inf)f=0;
	}
	for(int i=0;i<l;i++)if(b[i]=='*')if(!c1)c1=i+1;else c2=i+1;
	while(T--){
		scanf("%d%I64d",&n,&k);
		printf("%c",gao(n,k));
	}
	return 0;
}
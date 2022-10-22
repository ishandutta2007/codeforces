#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define Mod 20040901
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid (l+r>>1)
#define MN 300005
int sum[2][MN<<2],P[MN],a[MN],n;
void pushup(int op,int x){
	sum[op][x]=sum[op][Ls]+sum[op][Rs];
}
void change(int op,int x,int l,int r,int loc){
//	cout<<"add: "<<op<<" "<<l<<" "<<r<<endl;
	sum[op][x]=(sum[op][x]+P[loc])%Mod;
	if(l==r)return;
	if(loc<=mid)change(op,Ls,l,mid,loc);
		else change(op,Rs,mid+1,r,loc);
}
int ask(int op,int x,int l,int r,int b,int e){
	if(b<=l&&r<=e) {/*cout<<"get: "<<l<<" "<<r<<endl;*/return sum[op][x];}
	if(l>e||r<b) return 0;
	return (ask(op,Ls,l,mid,b,e)+ask(op,Rs,mid+1,r,b,e))%Mod;
}
int main(){
	scanf("%d",&n);
	P[0]=1;
	for(int i=1;i<=n;++i)P[i]=(LL)P[i-1]*(n+1)%Mod;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		int len=min(a[i]-1,n-a[i]),t1=a[i],t2=n-a[i]+1;
		int hash1=ask(0,1,1,n,t1-len,t1),hash2=ask(1,1,1,n,t2-len,t2);
		if(t1<t2) hash1=(LL)hash1*P[t2-t1]%Mod;
			else hash2=(LL)hash2*P[t1-t2]%Mod;
	//	cout<<i<<": "<<len<<" "<<t1<<" "<<t2<<" "<<hash1<<" "<<hash2<<endl;
		if(hash1!=hash2){
			puts("YES");
			return 0;
		}
		change(0,1,1,n,a[i]);
		change(1,1,1,n,n-a[i]+1);
	}
	puts("NO");
	return 0;
}
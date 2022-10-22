#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,c,b,Mod,phi;
inline int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
#define MN 1000005
char c1[MN],c2[MN];
int main(){
	scanf("%s%s%d",c1,c2,&c);
//	(b-1)b^(n-1)%c
	Mod=c;
	phi=c;
	for(int i=2;i*i<=c;++i){
		if(c%i==0){
			phi-=phi/i;
			while(c%i==0)c/=i;
		}
	}
	if(c!=1) phi=phi-phi/c;
	int ln=strlen(c1);
	for(int i=0;i<ln;++i){
		b=((LL)b*10+c1[i]-'0')%Mod;
	}
	int B=(b-1+Mod)%Mod;
	ln=strlen(c2);
	bool bol=0;
	for(int i=0;i<ln;++i){
		if((LL)n*10+c2[i]-'0'>=phi)bol=1;
		n=((LL)n*10+c2[i]-'0')%phi;
	}
	n=(n-1+phi)%phi;
//	n=n%phi;
	if(bol)n+=phi;
//	cout<<"HI "<<n<<" "<<phi<<" "<<ksm(b,n)<<endl;
	int ans=(LL)B*ksm(b,n)%Mod;
	printf("%d",ans==0?Mod:ans);
}
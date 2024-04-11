#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int B=1<<18;
int len,bg;long long p,pw[B+10];char s[40];map<long long,int> mp;
inline long long mod(long long a){
	if(a<(1ll<<(len-bg))) return a;
	return a^p;
}
inline long long mul(long long a,long long b){
	long long res=0;
	for(int i=0;i<=len-bg;++i,a<<=1,a=mod(a)) if((b>>i)&1) res^=a;
	return mod(res);
}
int main(){
	scanf("%s",s+1);len=strlen(s+1);
	for(bg=1;bg<=len&&s[bg]<49;++bg);
	if(bg>len){printf("-1");return 0;}
	for(;s[len]<49;--len);
	for(int i=len;i>=bg;--i) p=p*2+s[i]-48;
	if(p<2){printf("%d %d",bg,bg+1);return 0;}
	for(int i=pw[0]=1;i<=B;++i) pw[i]=mul(pw[i-1],2),mp[pw[i-1]]=i-1;
	for(long long ans=B,v=pw[B];1;v=mul(v,pw[B]),ans+=B)
		if(mp[v]){printf("%d %lld",bg,bg+ans-mp[v]);break;}
	return 0;
}
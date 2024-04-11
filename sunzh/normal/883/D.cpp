#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
char s[1000010];
int st[1000010];
int pos[1000010];
int pre[1000010];
int suf[1000010];
int tp,len;
int f[1000010];
bool check(int x){
	memset(f,-0x3f,sizeof(f));
	suf[0]=1;
	for(int i=1;i<=tp;++i){
		f[i]=max(f[i],f[i-1]);
		if(pre[i]==0||f[i-1]+x>=pos[pre[i]]||pos[pre[i]]<st[i-1]){
			f[i]=st[i];
		}
		else{
			int j=suf[i-1];
			if(j<=len&&st[i]-pos[j]>x) return 0;
			if(i>=2){
				j=suf[i-2];
				if(j>len||st[i]-pos[j]<=x) f[i]=st[i-1];
			}
		}
		suf[i]=suf[i-1];
		while(suf[i]<=len&&pos[suf[i]]<=max(st[i],f[i]+x)) ++suf[i];
	}
	return max(st[tp],f[tp]+x)>=pos[len];
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) {
		if(s[i]=='*') pos[++len]=i;
		else if(s[i]=='P') st[++tp]=i,pre[tp]=len;
	}
	if(tp==0){
		printf("0 0\n");return 0;
	}
	if(tp==1){
		if(pre[tp]>(len>>1)) printf("%d %d\n",pre[tp],st[tp]-pos[1]);
		else if(((len>>1)<<1)==len&&pre[tp]==(len>>1)) printf("%d %d\n",len>>1,min(st[tp]-pos[1],pos[len]-st[tp]));
		else printf("%d %d\n",len-pre[tp],pos[len]-st[tp]);
		return 0;
	}
	int l=0,r=n;
	int ans=0x3f3f3f3f;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d %d\n",len,ans);
	return 0;
}
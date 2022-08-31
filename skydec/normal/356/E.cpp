#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
const int MAXN=210000;
char a[MAXN];ULL ha[MAXN],po[MAXN];
const ULL base=99999997ll;int sum[MAXN][27];
int n;int na,nb;
map<int,bool>hf[MAXN];
inline ULL getLR(int l,int r){
	return ha[r]-ha[l-1]*po[r-l+1];
}
inline int num(int l,int r,int d){
	return sum[r][d]-sum[l-1][d];
}
bool ck(int l,int r){
	if(l==r)return 1;
	if(hf[l].find(r)!=hf[l].end())return hf[l][r];
	int mid=(l+r)>>1;bool flag=1;
	if(num(l,mid-1,a[mid]-'a')!=0)flag=0;
	if(num(mid+1,r,a[mid]-'a')!=0)flag=0;
	if(getLR(l,mid-1)!=getLR(mid+1,r))flag=0;
	flag&=ck(l,mid-1);
	flag&=ck(mid+1,r);
	hf[l][r]=flag;
	return flag;
}
LL old[MAXN];LL res=0;
LL dfs(int l,int r,ULL hp){
	//if(na==5&&nb=='j'-'a')printf("%d %d\n",l,r);
	LL rp=(r-l+1)*1ll*(r-l+1);
	int len=(r-l+1);
	if(r+1+len<=n)if(!num(r+2,r+1+len,a[r+1]-'a')&&hp==getLR(r+2,r+1+len))
	rp+=dfs(l,r+1+len,(hp+hp*po[len+1]+(a[r+1]-'a')*po[len]));
	
	if(l-1-len>=1)if(!num(l-1-len,l-2,a[l-1]-'a')&&hp==getLR(l-1-len,l-2))
	rp+=dfs(l-1-len,r,(hp+hp*po[len+1]+(a[l-1]-'a')*po[len]));
	
	return rp;
}
int main(){
	scanf("%s",a+1);n=strlen(a+1);po[0]=1;
	rep(i,1,n){
		ha[i]=ha[i-1]*base;
		ha[i]+=1ll*(a[i]-'a');
		po[i]=po[i-1]*base;
		rep(j,0,25)sum[i][j]=sum[i-1][j];
		sum[i][a[i]-'a']++;
	}
	rep(i,1,n)for(int j=1;i+j<=n&&i-j>=1;j=j*2+1)if(ck(i-j,i+j)){
		int l=i-j;int r=i+j;
		res+=(r-l+1)*1ll*(r-l+1);
		old[l]+=(r-l+1)*1ll*(r-l+1);
		old[r+1]-=(r-l+1)*1ll*(r-l+1);
	}
	res+=1ll*n;
	LL ans=res;
	rep(i,1,n)old[i]+=old[i-1];
	rep(i,1,n)old[i]++;
	rep(i,1,n)rep(j,0,25){
		na=i;nb=j;
		LL tmp=res-old[i];
		tmp+=dfs(i,i,j);
		for(int len=1;len+i<=n&&i-len>=1;len=len*2+1)
		if(ck(i-len,i-1)&&ck(i+1,i+len)&&!num(i-len,i-1,j)&&!num(i+1,i+len,j)&&getLR(i-len,i-1)==getLR(i+1,i+len))
		tmp+=dfs(i-len,i+len,getLR(i-len,i+len)+(j-(a[i]-'a'))*po[len]);
		ans=max(ans,tmp);
	}
	printf("%I64d\n",ans);
	return 0;
}
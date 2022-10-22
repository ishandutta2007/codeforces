#pragma GCC optimize(3)
#include<iostream>
#include<vector>
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
int n;
bool flag;
const int N=100010,NN=1000010;
string str[N];
int len[N];
int mod[3]={(int)1e9+7,(int)1e9+9,998244353};
int pri[3]={29,31,37};
int inv[3]={758620695,838709685,242816194};
const int modl=1e9+7;
vector<int>hsh[3][N];
vector<int>sorted[N];
int nxt[NN],a[NN];
int dp[2][NN];
int gethash(int t,int i,int p,int x){
	if(x<p) return hsh[t][i][x+1];
	return (hsh[t][i][p]+1ll*(hsh[t][i][x+2]-hsh[t][i][p+1]+mod[t])%mod[t]*inv[t]%mod[t])%mod[t];
}
pair<int,pair<int,int> > get_h(int i,int p,int x){
	return make_pair(gethash(0,i,p,x),make_pair(gethash(1,i,p,x),gethash(2,i,p,x)));
}
char getc(int i,int x,int l) {
	if(l<x) return str[i][l];
	else return str[i][l+1];
}
bool check(int x,int y,int a,int b){
	int t=-1;
	int lenx=len[x]-(y==len[x]?1:2),lena=len[a]-(b==len[a]?1:2);
	int l=0,r=min(lenx,lena);
	if(get_h(x,y,len[x]-(y==len[x]?1:2))==get_h(a,b,len[a]-(b==len[a]?1:2))) return 1;
	while(l<=r){
		int mid=l+r>>1;
		if(get_h(x,y,mid)==get_h(a,b,mid)){
			t=mid;l=mid+1;
		}
		else r=mid-1;
	}
	return getc(x,y,t+1)>=getc(a,b,t+1);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>str[i];
	for(int i=1;i<=n;++i) len[i]=str[i].size();
	for(int j=0;j<3;++j){
		for(int i=1;i<=n;++i){
			hsh[j][i].pb(0);
			int s=1,tmp=0;
			for(int k=0;k<len[i];++k){
				tmp=(tmp+1ll*s*(str[i][k]-'a'+1))%mod[j];
				s=1ll*s*pri[j]%mod[j];
				hsh[j][i].pb(tmp);
			}
//			hsh[j][i].pb(-1);
		}
	}
	for(int i=1;i<=n;++i){
		nxt[len[i]-1]=len[i]-1;
		for(int j=len[i]-2;j>=0;--j){
			if(str[i][j]!=str[i][j+1]) nxt[j]=j+1;
			else nxt[j]=nxt[j+1];
		}
		int l=0,r=len[i]-1;
		for(int j=0;j<=len[i]-1;++j){
			if(str[i][j]>=str[i][nxt[j]]) a[l++]=j;
			else a[r--]=j;
		}
		for(int j=0;j<len[i];++j){
			sorted[i].pb(a[j]);
			if(a[j]==len[i]-1) sorted[i].pb(len[i]);
		}
	}
//	printf("%d %d %d %d %d %d\n",gethash(0,1,0,5),gethash(0,1,1,5),gethash(0,1,2,5),gethash(0,1,3,5),gethash(0,1,4,5),gethash(0,1,5,5));
	for(int i=0;i<=len[1];++i) dp[flag][i]=1;
	for(int i=2;i<=n;++i){
		flag^=1;
		int sum=0,pos=0,it=0;
		for(auto j:sorted[i]){
			while(it<sorted[i-1].size()&&check(i,j,i-1,sorted[i-1][it])){
				sum+=dp[flag^1][it];if(sum>=modl) sum-=modl;++it;
			}
			dp[flag][pos]=sum;
			++pos;
		}
	}
	int ans=0;
	for(int i=0;i<=len[n];++i){
		ans+=dp[flag][i];
		if(ans>=modl) ans-=modl;
	}
	cout<<ans<<"\n";
	return 0;
}
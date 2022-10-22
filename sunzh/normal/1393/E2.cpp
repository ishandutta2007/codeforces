#include<bits/stdc++.h>
using namespace std;
int n;
bool flag;
const int N=100010,NN=1000010;
string str[N];
int len[N];
long long mod[1]={(long long)1e9+7};
int pri[1]={29};
long long inv[1]={758620695};
long long  P[1][NN];
const long long modl=1e9+7;
vector<long long>hsh[2][N];
vector<int>sorted[N];
int nxt[NN],a[NN];
int dp[2][NN];
inline long long gethash(int t,int i,int p,int x){
	if(x<p) return hsh[t][i][x+1];
	return (hsh[t][i][p]+1ll*(hsh[t][i][x+2]-hsh[t][i][p+1]+mod[t])%mod[t]*inv[t]%mod[t])%mod[t];
}
inline long long get_h(int i,int p,int x){
	return gethash(0,i,p,x);
}
inline char getc(int i,int x,int l) {
	if(l<x) return str[i][l];
	else if(l+1<len[i]) return str[i][l+1];
	else return ' ';
}
inline bool check(int x,int y,int a,int b){
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
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
	cin>>n;
	P[0][0]=P[1][0]=1;
	int maxl=0;
	for(int i=1;i<=n;++i) cin>>str[i];
	for(int i=1;i<=n;++i) len[i]=str[i].size(),maxl=max(maxl,len[i]);
	for(int j=0;j<1;++j) for(int i=1;i<=maxl;++i) P[j][i]=P[j][i-1]*pri[j]%mod[j];
	for(int j=0;j<1;++j){
		for(int i=1;i<=n;++i){
			hsh[j][i].push_back(0);
			for(int k=0;k<len[i];++k){
				hsh[j][i].push_back((hsh[j][i][k]+1ll*P[j][k]*(str[i][k]-'a'+1))%mod[j]);
			}
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
			sorted[i].push_back(a[j]);
			if(a[j]==len[i]-1) sorted[i].push_back(len[i]);
		}
	}
	for(int i=0;i<=len[1];++i) dp[flag][i]=1;
	for(int i=2;i<=n;++i){
		flag^=1;
		int sum=0;
		int pos=0,it=0;
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
	cout<<ans<<'\n';
	return 0;
}
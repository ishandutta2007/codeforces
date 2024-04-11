#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int a[100010],tar[100010];
set<int>s0,s1;
long long ans;
int n;
void solve(){
	long long res=0;
	int ad0=0,ad1=0;
	for(int i=1;i<=n;++i){
		if(tar[i]==0){
			if(!s0.size()) return ;
			int p=*s0.begin();s0.erase(p);
			res+=abs(p-i);
		}
		else{
			if(!s1.size()) return ;
			int p=*s1.begin();s1.erase(p);
			res+=abs(p-i);
		}
	}
	ans=min(ans,res);
}
int main(){
	int T=read();
	while(T--){
		int cnt0=0,cnt1=0;
		n=read();for(int i=1;i<=n;++i) a[i]=(read()&1);
		s0.clear(),s1.clear();
		for(int i=1;i<=n;++i){
			if(a[i]==0) ++cnt0,s0.insert(i);else ++cnt1,s1.insert(i);
		}
		ans=0x7f7f7f7f7f7f7f7f;
		if(cnt0>(n+1>>1)||cnt1>(n+1>>1)) printf("-1\n");
		else{
			for(int i=1;i<=n;++i) tar[i]=(i&1);
			solve();
			s0.clear(),s1.clear();
			for(int i=1;i<=n;++i){
				if(a[i]==0) ++cnt0,s0.insert(i);else ++cnt1,s1.insert(i);
			}
			for(int i=1;i<=n;++i) tar[i]=(~i&1);
			solve();
			printf("%lld\n",ans>>1);
		}
	}
}
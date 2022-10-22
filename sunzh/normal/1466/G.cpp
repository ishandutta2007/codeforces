#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<array>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,q;
string s[31];
int len[31];
char t[100010],str[1000010];
const int N=1000000;
vector<int>hsh[31];
int m;
int pw2[2000010],pw[2000010];
const int bs=37;
const int mod=1e9+7;
int qpow(int x,int k=mod-2){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
int sub(int x,int y){
	return x<y?x-y+mod:x-y;
}
int main(){
	m=n=read(),q=read();
	cin>>s[0];len[0]=s[0].length();scanf("%s",t+1);
	vector<array<int,26> >pre(n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+t[i]+s[i-1];
		len[i]=(len[i-1]<<1|1);
		if(s[i].length()>=N){
			m=i;break ;
		}
	}
	pw2[0]=pw[0]=1;
	for(int i=1;i<=2*N;++i){
		pw2[i]=add(pw2[i-1],pw2[i-1]);
		pw[i]=mul(pw[i-1],bs);
	}
	for(int i=m+1;i<=n;++i){
		pre[i]=pre[i-1];
		pre[i][t[i]-'a']=add(pre[i][t[i]-'a'],qpow(pw2[i]));
	}
	for(int i=0;i<=m;++i){
		hsh[i].assign(s[i].length()+1,0);
		for(int j=1;j<=s[i].length();++j){
			hsh[i][j]=add(mul(bs,hsh[i][j-1]),s[i][j-1]-'a'+1);
		}
	}
	auto gethsh=[&](vector<int>&h,int l,int r){
		if(l>r) return 0;
		return sub(h[r],mul(h[l-1],pw[r-l+1]));
	};
	
	while(q--){
		int k=read();
		scanf("%s",str+1);
		int l=strlen(str+1);
		int ans=0;
		vector<int>ha(l+1);
		for(int i=1;i<=l;++i) ha[i]=add(mul(ha[i-1],bs),str[i]-'a'+1);
		auto lok=[&](int x){
			return gethsh(hsh[m],len[m]-x+1,len[m])==gethsh(ha,1,x);
		};
		auto rok=[&](int x){
			return gethsh(hsh[m],1,l-x+1)==gethsh(ha,x,l);
		};
		for(int i=0;i<=k;++i){
			if(i>m) break ;
			if(i==0){
				for(int j=1;j<=len[i];++j){
					int r=j+l-1;
					if(r>len[i]) break ;
					if(gethsh(hsh[i],j,r)==ha[l]){
						ans=add(ans,pw2[k-i]);
					}
				}
			}
			else{
				int mid=(1+len[i]>>1);
				for(int j=1;j<=mid&&j<=l;++j){
					int L=mid-j+1;int R=L+l-1;
					if(L<=0) break ;
					if(R>len[i]) continue ;
					if(gethsh(hsh[i],L,R)==ha[l]){
						ans=add(ans,pw2[k-i]);
					}
				}
			}
		}
		if(k<=m){
			printf("%d\n",ans);continue ;
		}
		for(int i=1;i<=l;++i){
			if(lok(i-1)&&rok(i+1)){
				ans=add(ans,mul(pre[k][str[i]-'a'],pw2[k]));
			}
		}
		printf("%d\n",ans);
	}
}
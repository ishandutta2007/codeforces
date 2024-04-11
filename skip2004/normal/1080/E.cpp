#include<bits/stdc++.h>
using namespace std;
template <typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template <typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
namespace io{
	struct input{
		inline input(){ios::sync_with_stdio(false),cin.tie(0);}	
		template <typename _>inline input& operator , (_&x){cin>>x;return*this;}
		template <typename _>inline input& operator >>(_&x){cin>>x;return*this;}
	};
	struct output{
		template <typename _>inline output& operator, (const _&x){cout<<x;return*this;}
		template <typename _>inline output& operator>>(const _&x){cout<<x;return*this;}
	};
}
struct chr{
	short cnt[26];
	inline void ins(char x){++cnt[x-'a'];}
	inline chr operator - (chr b){
		chr c;for(int i=0;i<26;++i)c.cnt[i]=cnt[i]-b.cnt[i];
		return c;
	}
	inline int operator ==(chr b){
		for(int i=0;i<26;++i)if(cnt[i]!=b.cnt[i])return 0;
		return 1;
	}
}f[260][260],NU,___,___2;
io::input in;
io::output out;
int n,m;
string s[1000];
int a[1000][1000];
int chk[1000];
chr b[1000];
int p[1000],tot;
long long ans=0;
inline int solve(){
	b[tot+1]=___2;
	for(int i=1;i<tot;++i)p[i]=0;
	for(int i=1,mx=0,id=0;i<tot;++i){
		if(mx>i)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1; 
		while(b[i+p[i]]==b[i-p[i]]) p[i]++; 
		if(p[i]+i>mx)mx=p[i]+i,id=i;
		if(i%2)ans+=p[i]+1>>1;
		else ans+=p[i]>>1;
	}
	tot=0;
}
inline void ins(chr x){
	b[++tot]=x,b[++tot]=___;
}
int main(){
	___.cnt[0]=-1;
	___2.cnt[0]=-2;
	in,n,m;
	for(int i=0;i<n;++i)in,s[i];
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			a[i][j]=(j?a[i][j-1]:0)^1<<s[i][j]-'a';
			if(j)f[i][j]=f[i][j-1];
			f[i][j].ins(s[i][j]);
		}
	}
	for(int i=0;i<m;++i)
		for(int j=i;j<m;++j){
			for(int k=0;k<n;++k){
				if(__builtin_popcount(a[k][j]^(i?a[k][i-1]:0))<2)ins(f[k][j]-(i?f[k][i-1]:NU));
				else solve();
			}
			solve();
		}
	out,ans;
}
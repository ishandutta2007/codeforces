#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define Mod 1000000007
#define MN 1000005
#define mn 100005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int n,len,q,m,k;
int a[MN];
char ch[MN],w[MN],s[105],T[MN];
int f[mn][26],pw[mn];
int ok[MN],GG[105];;
int work(int now,string &s){
	if(!s.size()){
		return pw[k-now+1];;
	}
	if(k<now)return 0;
	if(s.size()==1){
//		cerr<<"? "<<f[k][s[0]-'a']<<endl;
		assert('a'<=s[0]&&s[0]<='z');
		return (f[k][s[0]-'a']-f[now-1][s[0]-'a']*pw[k-now+1]%Mod+Mod)%Mod;
	}
	bool ok=1;
	int res=0;
	string tmp;tmp.clear();
	for(int i=0;i<s.size();i+=2){
		if(s[i]!=T[now]) {ok=0;break;}
	}
	if(ok){
		for(int i=1;i<s.size();i+=2)tmp+=s[i];
		res=work(now+1,tmp);
	}
	ok=1;
	tmp.clear();
	for(int i=1;i<s.size();i+=2)
		if(s[i]!=T[now]) {ok=0;break;}
	if(ok){
		for(int i=0;i<s.size();i+=2)tmp+=s[i];
		res=(res+work(now+1,tmp))%Mod;
	}
	return res;
}
signed main(){
	n=read();q=read();
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*2%Mod;
	scanf("%s",s+1);len=strlen(s+1);
	scanf("%s",T+1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)
			f[i][j]=(f[i-1][j]*2)%Mod;
		f[i][T[i]-'a']++;
		f[i][T[i]-'a']%=Mod;

	}
	for(int i=1;i<=q;++i){
		k=read();scanf("%s",w+1);
		int l=strlen(w+1);
		int ans=0;
		for(int k=1;k<=len+1;++k){
			int now=k;
			string s;s.clear();
			bool ok=1;
			for(int j=1;j<=l;++j){
				if(now==len+1){s.push_back(w[j]);now=1;continue;}
				if(::s[now]!=w[j]){ok=0;break;}
				now++;
			}
			if(ok){
				ans=(ans+work(1,s))%Mod;
//				cerr<<"ok: "<<k<<" "<<s<<" "<<work(1,s)<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1.5e5+5;

int n,q;
int dep[N],fa[N];
bool leaf[N];
char co[N];
int son[N];
int tp[N],be[N];
vector<int>ss[N];
int f[N][26],sv[N][26];
bool bz[N];
bool can[N];
int Mx[N];

int main(){
	n=get();q=get();
	fo(i,1,n)leaf[i]=1;
	fo(i,2,n){
		int x=get();
		char ch;
		while(ch=getchar(),(ch<'a'||ch>'z')&&ch!='?');
		co[i]=ch;
		leaf[x]=0;
		dep[i]=dep[x]+1;
		fa[i]=x;
		son[x]++;
	}
	int mi=1e9,mx=0;
	fo(i,1,n)if (leaf[i])mi=min(mi,dep[i]),mx=max(mx,dep[i]);
	if (mi!=mx){
		fo(i,1,q)printf("Fou\n");
		return 0;
	}
	int Len=mx;
	fo(i,2,n){
		if (fa[i]==1)tp[i]=1;
		else{
			if (son[fa[i]]==1)tp[i]=tp[fa[i]];
			else tp[i]=fa[i];
		}
	}
	fd(i,n,2)
	if (!be[i]){
		for(int x=i;x!=tp[i];x=fa[x])be[x]=i;
		ss[tp[i]].push_back(i);
		bz[i]=1;
	}
	bz[1]=1;
	fo(i,2,n)
		if(co[i]!='?')sv[be[i]][co[i]-'a']++;
	int cnt=0;
	fd(i,n,1)
	if(bz[i]){
		fo(x,0,25)f[i][x]=0;
		for(auto x:ss[i])
			fo(c,0,25)
			f[i][c]=max(f[i][c],f[x][c]+sv[x][c]);
		int sum=0;
		fo(c,0,25)sum=sum+f[i][c];
		can[i]=sum<=Len-dep[i];
		if (!can[i])cnt++;
	}
	fo(cas,1,q){
		int x=get();
		char ch;
		while(ch=getchar(),(ch<'a'||ch>'z')&&ch!='?');
		if (co[x]!='?')sv[be[x]][co[x]-'a']--;
		co[x]=ch;
		if (co[x]!='?')sv[be[x]][co[x]-'a']++;
		x=tp[be[x]];
		for(;x;x=tp[x]){
			if (!can[x])cnt--;
			fo(c,0,25)f[x][c]=0;
			for(auto y:ss[x])
				fo(c,0,25)
				f[x][c]=max(f[x][c],f[y][c]+sv[y][c]);
			int sum=0;
			fo(c,0,25)sum+=f[x][c];
			can[x]=(sum<=Len-dep[x]);
			if (!can[x])cnt++;
		}
		int sum=0;
		fo(c,0,25)sum+=f[1][c];
		if (cnt)printf("Fou\n");
		else{
			printf("Shi ");
			LL ans=0;
			fo(c,0,25)ans=ans+1ll*(c+1)*(Len-sum+f[1][c]);
			cout<<ans<<endl;
		}
	}
	return 0;
}
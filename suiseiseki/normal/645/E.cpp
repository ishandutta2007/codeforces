#include <cstdio>
#define ll long long
#define Maxn 1000000
#define Mod 1000000007
int f[Maxn<<1|5];
int g[30];
int las[30];
char s[Maxn+5];
int add(int x,int y){
	ll ans=x;
	ans+=y;
	if(ans<0){
		ans+=Mod;
	}
	else if(ans>Mod){
		ans-=Mod;
	}
	return (int)ans;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int m=0;
	while(s[++m]!='\0');
	m--;
	f[0]=1;
	for(int i=1;i<=m;i++){
		f[i]=f[i-1];
		f[i]=add(f[i],f[i-1]);
		if(las[s[i]-'a']>0){
			f[i]=add(f[i],-g[s[i]-'a']);
		}
		g[s[i]-'a']=add(g[s[i]-'a'],add(f[i],-f[i-1]));
		las[s[i]-'a']=i;
	}
	int id;
	for(int i=m+1;i<=m+n;i++){
		id=0;
		for(int j=1;j<k;j++){
			if(las[j]<las[id]){
				id=j;
			}
		}
		las[id]=i;
		f[i]=f[i-1];
		f[i]=add(f[i],f[i-1]);
		if(las[id]>0){
			f[i]=add(f[i],-g[id]);
		}
		g[id]=add(g[id],add(f[i],-f[i-1]));
	}
	printf("%d\n",f[n+m]);
	return 0;
}
//////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=200005,mod=1e9+7;
struct node{
	int to,next;
}p[N<<1];
int n,head[N],dep[N],pw[N],tot,tmp,si;

inline void add(int x,int y){
	p[++tot]=(node){y,head[x]};head[x]=tot;
	p[++tot]=(node){x,head[y]};head[y]=tot;
}

inline void dfs(int x,int fa){
	si++;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		if(dep[y]){
			if(dep[y]<dep[x]) tmp=dep[x]-dep[y];
			continue;
		}
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
}

int main(){
	scanf("%d",&n);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=(ll)pw[i-1]*2%mod;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(dep[i]) continue;
		dep[i]=1;si=0;tmp=0;dfs(i,-1);
		si--;tmp=max(tmp,1);
//		printf("%d %d\n",si,tmp);
		ans=(ll)ans*((ll)(pw[tmp]-2)*pw[si-tmp]%mod+pw[si])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
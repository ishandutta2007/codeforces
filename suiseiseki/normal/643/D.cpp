#include <set>
#include <cstdio>
using namespace std;
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=100000;
int n,q;
int deg[Maxn+5],f[Maxn+5];
bool vis[Maxn+5];
ll a[Maxn+5],t[Maxn+5];
multiset<ll> s[Maxn+5];
void del(int x){
	if(vis[x]&&!s[x].empty()){
		vis[x]=0;
		s[0].erase(s[0].find((*s[x].begin())+t[x]/(deg[x]+1)));
		s[0].erase(s[0].find((*(--s[x].end()))+t[x]/(deg[x]+1)));
	}
}
void add(int x){
	if(!vis[x]&&!s[x].empty()){
		vis[x]=1;
		s[0].insert((*s[x].begin())+t[x]/(deg[x]+1));
		s[0].insert((*(--s[x].end()))+t[x]/(deg[x]+1));
	}
}
void work(int i,int j){
	del(f[i]);
	del(f[f[i]]);
	del(f[f[f[i]]]);
	del(j);
	del(f[j]);
	del(f[f[j]]);
	s[f[i]].erase(s[f[i]].find(a[i]));
	s[f[f[i]]].erase(s[f[f[i]]].find(a[f[i]]));
	a[f[i]]-=t[i]/(deg[i]+1);
	a[f[i]]-=t[f[i]]-deg[f[i]]*(t[f[i]]/(deg[f[i]]+1));
	a[f[i]]+=t[f[i]]-(deg[f[i]]-1)*(t[f[i]]/deg[f[i]]);
	s[f[f[i]]].insert(a[f[i]]);
	s[f[f[f[i]]]].erase(s[f[f[f[i]]]].find(a[f[f[i]]]));
	a[f[f[i]]]-=t[f[i]]/(deg[f[i]]+1);
	a[f[f[i]]]+=t[f[i]]/deg[f[i]];
	s[f[f[f[i]]]].insert(a[f[f[i]]]);
	deg[f[i]]--;
	deg[j]++;
	s[j].insert(a[i]);
	s[f[j]].erase(s[f[j]].find(a[j]));
	a[j]+=t[i]/(deg[i]+1);
	a[j]-=t[j]-(deg[j]-1)*(t[j]/deg[j]);
	a[j]+=t[j]-deg[j]*(t[j]/(deg[j]+1));
	s[f[j]].insert(a[j]);
	s[f[f[j]]].erase(s[f[f[j]]].find(a[f[j]]));
	a[f[j]]-=t[j]/deg[j];
	a[f[j]]+=t[j]/(deg[j]+1);
	s[f[f[j]]].insert(a[f[j]]);
	add(f[i]);
	add(f[f[i]]);
	add(f[f[f[i]]]);
	add(j);
	add(f[j]);
	add(f[f[j]]);
	f[i]=j;
}
int main(){
	read(n),read(q);
	for(int i=1;i<=n;i++){
		read(t[i]);
	}
	for(int i=1;i<=n;i++){
		read(f[i]);
	}
	for(int i=1;i<=n;i++){
		deg[i]++;
		deg[f[i]]++;
	}
	for(int i=1;i<=n;i++){
		a[i]+=t[i]-deg[i]*(t[i]/(deg[i]+1));
		a[f[i]]+=t[i]/(deg[i]+1);
	}
	for(int i=1;i<=n;i++){
		s[f[i]].insert(a[i]);
	}
	for(int i=1;i<=n;i++){
		add(i);
	}
	for(int i=1;i<=q;i++){
		int op;
		read(op);
		if(op==1){
			int x,y;
			read(x),read(y);
			work(x,y);
		}
		else if(op==2){
			int x;
			read(x);
			printf("%lld\n",a[x]+t[f[x]]/(deg[f[x]]+1));
		}
		else{
			printf("%lld %lld\n",(*s[0].begin()),(*(--s[0].end())));
		}
	}
	return 0;
}
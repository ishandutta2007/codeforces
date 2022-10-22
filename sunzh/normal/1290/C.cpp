#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,k;
vector<int>belong[300010];
long long val[600010];
int fa[600010];
int ans;
char s[300010];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int v(int x){
	return min(val[find(x)],val[find(x+k)]);
}
signed main(){
	n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=2*k+1;++i) fa[i]=i;
	val[k<<1|1]=k+1;
	for(int i=1;i<=k;++i) val[i]=1;
	for(int i=1;i<=k;++i){
		int c=read();
		for(int j=1;j<=c;++j){
			int x=read();
			belong[x].push_back(i);
		}
	}
	for(int i=1;i<=n;++i){
		val[find(k<<1|1)]=k+1;
		if(belong[i].size()==1){
			int j=belong[i][0];ans-=v(j);
			if(s[i]=='0'){
				int fx=find(j+k),fy=find(k<<1|1);
				if(fx!=fy){
					fa[fx]=fy,val[fy]+=val[fx];
				}
			}
			else {
				int fx=find(j),fy=find(k<<1|1);
				if(fx!=fy){
					fa[fx]=fy,val[fy]+=val[fx];
				}
			}
			ans+=v(j);
		}
		else if(belong[i].size()==2){
			int x=belong[i][0],y=belong[i][1];
			if(s[i]=='0'){
				int fx=find(x),fy=find(y+k);
				if(fx!=fy){
					ans-=v(x)+v(y);fa[fx]=fy,val[fy]+=val[fx];fx=find(y),fy=find(x+k);fa[fx]=fy,val[fy]+=val[fx];ans+=v(x);
				}
			}
			else{
				int fx=find(x),fy=find(y);
				if(fx!=fy){
					ans-=v(x)+v(y);fa[fx]=fy,val[fy]+=val[fx];fx=find(x+k),fy=find(y+k);fa[fx]=fy,val[fy]+=val[fx];ans+=v(x);
				}
			}
		}
		print(ans);putchar('\n');
	}
	return 0;
}
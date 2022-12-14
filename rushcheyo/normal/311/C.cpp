#include<bits/stdc++.h>
using namespace std;
template<typename T>
void rd(T&x){
	char c;while((c=getchar())<'0'||c>'9');
	for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
}
typedef long long ll;
const int N=100005,M=10005;
ll h,a[N],d[M],md[M];
int n,m,k,c[N],tot;
struct cmp{bool operator()(int p,int q){return c[p]==c[q]?p<q:c[p]>c[q];}};
set<int,cmp>s;
struct node{int x;ll d;};
bool operator<(const node&a,const node&b){return a.d>b.d;}
priority_queue<node>q;
void rebuild(){
	for(int i=0;i<k;i++)d[i]=h+1;
	q.push((node){1%k,1});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(d[t.x]!=h+1)continue;
		d[t.x]=t.d;
		for(int i=0;i<tot;i++)
			if(d[(t.x+md[i])%k]>t.d+md[i])
				q.push((node){(t.x+md[i])%k,t.d+md[i]});
	}
	s.clear();
	for(int i=1;i<=n;i++)
		if(a[i]>=d[a[i]%k])s.insert(i);
}
int main(){
	rd(h),rd(n),rd(m),rd(k);
	for(int i=1;i<=n;i++)rd(a[i]),rd(c[i]);
	rebuild();
	while(m--){
		int op;rd(op);
		if(op==1){
			rd(md[tot++]);
			rebuild();
		}else if(op==2){
			int x,y;rd(x),rd(y);
			bool fg=a[x]>=d[a[x]%k];
			if(fg)s.erase(x);
			c[x]-=y;
			if(fg)s.insert(x);
		}else{
			if(s.empty())puts("0");
			else{
				printf("%d\n",c[*s.begin()]);
				a[*s.begin()]=0;
				s.erase(s.begin());
			}
		}
	}
			
}
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e5+10;

int t,n,head[N],top,ans,hed[N],topp,dfn[N],l[N],r[N],tp,tot;
struct osc{
	int to,next;
}a[N<<1],e[N<<1];

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
	a[++top].to = f;
	a[top].next = head[t];
	head[t] = top;
}

inline void ade(int f,int t){
	e[++tp].to = t;
	e[tp].next = hed[f];
	hed[f] = tp;
	e[++tp].to = f;
	e[tp].next = hed[t];
	hed[t] = tp;
}

void dfss(int x,int f){
	l[x] = ++tot;
	for(int i=hed[x];~i;i = e[i].next) 
		if(e[i].to != f) dfss(e[i].to,x);
	r[x] = tot;
}

struct cmp{
	bool operator () (const int &x,const int &y) const{
		return l[x] < l[y];
	}
};
set<int,cmp>s;

void dfs(int x,int f){
	int tmp = 0;
	set<int,cmp>::iterator it = s.lower_bound(x);
	if( !(it != s.end() && r[x] >= l[*it]) ){
		if(it != s.begin() && r[*(--it)] >= l[x]) tmp = *it , s.erase(it);
		s.insert(x);
	}
	ans = max(ans,(int)s.size());
	for(int i=head[x];~i;i = a[i].next)
		if(a[i].to != f) dfs(a[i].to,x);
	if(s.count(x)) s.erase(x);
	if(tmp) s.insert(tmp);
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++) head[i] = hed[i] = -1; top = tp = tot = ans = 0;
		int fr;
		for(int i=1;i < n;i++) scanf("%d",&fr) , add(fr,i+1);
		for(int i=1;i < n;i++) scanf("%d",&fr) , ade(fr,i+1);
		dfss(1,0);
		dfs(1,0);
		printf("%d\n",ans);
	}
}
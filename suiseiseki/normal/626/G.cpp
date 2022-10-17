#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
const int Maxn=200000;
const double Inf=1e18;
const double eps=1e-10;
int n,t,q;
int p[Maxn+5],l[Maxn+5],c[Maxn+5];
double f(int x,int c){
	if(c==-1){
		return Inf;
	}
	if(c>=l[x]){
		return 0.0;
	}
	return 1.0*p[x]*l[x]/(c+1+l[x])/(c+l[x]);
}
double g(int x){
	return 1.0*p[x]*min(c[x],l[x])/(min(c[x],l[x])+l[x]);
}
struct Node{
	double val;
	int x,c;
	Node(int _x=0,int _c=-1){
		x=_x;
		c=_c;
		val=f(x,c);
	}
	friend bool operator <(Node a,Node b){
		if(fabs(a.val-b.val)>eps){
			return a.val<b.val;
		}
		return a.x<b.x;
	}
};
set<Node> nxt,used;
double ans;
void add(){
	set<Node>::iterator it=(--nxt.end());
	ans+=(it->val);
	int x=(it->x);
	used.erase(Node(x,c[x]-1));
	used.insert(*it);
	nxt.erase(it);
	nxt.insert(Node(x,++c[x]));
}
void del(){
	set<Node>::iterator it=used.begin();
	ans-=(it->val);
	int x=(it->x);
	nxt.erase(Node(x,c[x]));
	nxt.insert(*it);
	used.erase(it);
	used.insert(Node(x,(--c[x])-1));
}
int main(){
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
		nxt.insert(Node(i,0));
		used.insert(Node(i));
	}
	while(t--){
		add();
	}
	for(int i=1;i<=q;i++){
		int op,x;
		scanf("%d%d",&op,&x);
		op=(op==1?1:-1);
		nxt.erase(Node(x,c[x]));
		used.erase(Node(x,c[x]-1));
		ans-=g(x);
		l[x]+=op;
		nxt.insert(Node(x,c[x]));
		used.insert(Node(x,c[x]-1));
		ans+=g(x);
		while(((--nxt.end())->val)>((used.begin()->val)+eps)){
			del();
			add();
		}
		printf("%.7lf\n",ans);
	}
	return 0;
}
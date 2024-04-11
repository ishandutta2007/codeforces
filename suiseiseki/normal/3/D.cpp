/*#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define Maxn 50000
#define Inf (1ll<<60)
#define ll long long
int a[Maxn+5],b[Maxn+5];
int n,m;
char s[Maxn+5];
int id[Maxn+5];
map<pair<int,int>,ll> f;
ll mn(ll a,ll b){
	return a<b?a:b;
}
ll dfs(int x,int pos){
	if(pos<0){
		return Inf;
	}
	if(x>n){
		return pos==0?0:Inf;
	}
	pair<int,int> now=make_pair(x,pos);
	if(f.count(now)>0){
		return f[now];
	}
	if(s[x]=='('){
		return f[now]=dfs(x+1,pos+1);
	}
	if(s[x]==')'){
		return f[now]=dfs(x+1,pos-1);
	}
	return f[now]=mn(a[id[x]]+dfs(x+1,pos+1),b[id[x]]+dfs(x+1,pos-1));
}
ll ans;
char an[Maxn+5];
void work(int x,int pos){
	if(x>n){
		return;
	}
	if(pos<0){
		return;
	}
	if(s[x]=='('){
		an[x]=s[x];
		work(x+1,pos+1);
		return;
	}
	if(s[x]==')'){
		an[x]=s[x];
		work(x+1,pos-1);
		return;
	}
	if(dfs(x,pos)==dfs(x+1,pos+1)+a[id[x]]){
		an[x]='(';
		work(x+1,pos+1);
		return;
	}
	an[x]=')';
	work(x+1,pos-1);
	return;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			id[i]=++m;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	ans=dfs(1,0);
	if(ans>=Inf){
		puts("-1");
		return 0;
	}
	cout<<ans<<endl;
	work(1,0);
	puts(an+1);
	return 0;
}*/
/*#include <cstdio>
#include <queue>
using namespace std;
struct String{
	char s[50005];
	int len;
	void in(){
		scanf("%s",s+1);
		len=0;
		while(s[++len]!='\0');
		len--;
	}
	int size(){
		return len;
	}
	char &operator [](int x){
		return s[x];
	}
	void out(){
		for(int i=1;i<=len;i++){
			putchar(s[i]);
		}
	}
}a;
struct Node{
	int value;
	int t;
	friend bool operator >(Node p,Node q){
		return p.value>q.value;
	}
};
priority_queue<Node,vector<Node>,greater<Node> >q;
int main(){
	a.in();
	int now=0;
	long long ans=0;
	bool can=1;
	int x,y;
	for(int i=1;i<=a.size()&&can;i++){
		if(a[i]=='('){
			now++;
		}
		else{
			now--;
			if(a[i]=='?'){
				scanf("%d%d",&x,&y);
				q.push(((Node){x-y,i}));
				a[i]=')';
				ans+=y;
			}
		}
		if(now<0){
			if(q.empty()){
				can=0;
			}
			else{
				now+=2;
				a[q.top().t]='(';
				ans+=q.top().value;
				q.pop();
			}
		}
	}
	if(now){
		can=0;
	}
	if(!can){
		puts("-1");
	}
	else{
		printf("%I64d\n",ans);
		a.out();
		puts("");
	}
	return 0;
}*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 50000
#define ll long long
int f[Maxn+5];
int n;
char s[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
struct Question{
	int id;
	int a,b;
	friend bool operator <(Question p,Question q){
		return p.b-p.a<q.b-q.a;
	}
}a[Maxn+5];
struct Segment_Node{
	int left,right;
	int maxn,minn;
	int lazy;
}seg[Maxn<<2|5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].maxn=seg[root].minn=0;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void push_down(int root){
	seg[root<<1].lazy+=seg[root].lazy;
	seg[root<<1].maxn+=seg[root].lazy;
	seg[root<<1].minn+=seg[root].lazy;
	seg[root<<1|1].lazy+=seg[root].lazy;
	seg[root<<1|1].maxn+=seg[root].lazy;
	seg[root<<1|1].minn+=seg[root].lazy;
	seg[root].lazy=0;
}
int query_min(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].minn;
	}
	push_down(root);
	root<<=1;
	if(right<=seg[root].right){
		return query_min(root,left,right);
	}
	root|=1;
	if(left>=seg[root].left){
		return query_min(root,left,right);
	}
	root>>=1;
	return mn(query_min(root<<1,left,seg[root<<1].right),query_min(root<<1|1,seg[root<<1|1].left,right));
}
int query_max(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].maxn;
	}
	push_down(root);
	root<<=1;
	if(right<=seg[root].right){
		return query_max(root,left,right);
	}
	root|=1;
	if(left>=seg[root].left){
		return query_max(root,left,right);
	}
	root>>=1;
	return mx(query_max(root<<1,left,seg[root<<1].right),query_max(root<<1|1,seg[root<<1|1].left,right));
}
void update(int root,int left,int right,int x){
	if(seg[root].right==right&&seg[root].left==left){
		seg[root].lazy+=x;
		seg[root].maxn+=x;
		seg[root].minn+=x;
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			update(root,left,right,x);
		}
		else{
			update(root,left,seg[root].right,x);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			update(root,left,right,x);
		}
		else{
			update(root,seg[root].left,right,x);
		}
	}
	root>>=1;
	seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
int m;
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	build(1,1,n);
	int num=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			m++;
			scanf("%d%d",&a[m].a,&a[m].b);
			a[m].id=i;
			ans+=a[m].a;
			update(1,i,n,1);
			num++;
			s[i]='(';
		}
		else{
			if(s[i]=='('){
				update(1,i,n,1);
				num++;
			}
			else{
				update(1,i,n,-1);
				num--;
			}
		}
	}
	sort(a+1,a+1+m);
	if(num<0){
		puts("-1");
		return 0;
	}
	if(query_min(1,1,n)<0){
		puts("-1");
		return 0;
	}
	if(num&1){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m&&num>0;i++){
		if(query_min(1,a[i].id,n)>=2){
			update(1,a[i].id,n,-2);
			num-=2;
			ans+=a[i].b-a[i].a;
			s[a[i].id]=')';
		}
	}
	if(num>0){
		puts("-1");
		return 0;
	}
	printf("%I64d\n",ans);
	puts(s+1);
	return 0;
}
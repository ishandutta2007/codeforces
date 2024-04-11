#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 4e5+5;
const int mo = 1e9+7;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

struct matrix{
	LL a[5][5];
	LL *operator [](int x){return a[x];}
	
	//A+B x C
	//[A,B,C,BC,1]
	
	void init(){fo(i,0,4)fo(j,0,4)a[i][j]=0;}
	
	void digit(LL d){
		init();
		a[0][0]=a[1][1]=a[4][4]=1;
		a[2][2]=a[3][3]=10;
		a[1][3]=a[4][2]=d;
	}
	
	void plus(){
		init();
		a[0][0]=a[4][4]=a[3][0]=a[4][1]=1;
	}
	
	void multi(){
		init();
		a[0][0]=a[4][4]=a[3][1]=1;
	}
	
	friend matrix operator *(matrix a,matrix b){
		matrix c;
		fo(i,0,4)
			fo(j,0,4)
			c[i][j]=(a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j]+a[i][3]*b[3][j]+a[i][4]*b[4][j])%mo;
		return c;
	}
};
int n;
char s[N];
int pre[N];
int be[N],u,id[N],len[N],L;
int st[N],start[N];
int m;
int nxt[N];
int sta[N],top,to[N];

struct Vector{
	LL a[5];
	LL & operator [](int x){return a[x];}
	void init(){
		a[0]=a[2]=a[3]=0;
		a[1]=a[4]=1;
	}
};
Vector operator *(Vector a,matrix b){
	Vector c;
	fo(i,0,4)c[i]=(a[0]*b[0][i]+a[1]*b[1][i]+a[2]*b[2][i]+a[3]*b[3][i]+a[4]*b[4][i])%mo;
	return c;
}
int rmq[N][20];

int getmin(int l,int r){
	int t=log(r-l+1)/log(2);
	return min(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

matrix tree[N*2];
matrix val[N*2];
Vector ans;
int wr[N];
vector< pair<int,int> >qry[N];
int Ans[N];
int R[N];

void build(int now,int l,int r){
	if (l==r){
		tree[now]=val[l];
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	tree[now]=tree[ls]*tree[rs];
}

void query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		ans=ans*tree[now];
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	if (x<=mid)query(ls,l,mid,x,y);
	if (y>mid)query(rs,mid+1,r,x,y);
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n){
		pre[i]=pre[i-1];
		if (s[i]=='('){
			pre[i]++;
			sta[++top]=i;
		}
		if (s[i]==')'){
			pre[i]--;
			if (top)to[to[i]=sta[top--]]=i;
		}
	}
	fo(i,1,n)rmq[i][0]=pre[i];
	fo(j,1,log(n)/log(2))
		fo(i,1,n-(1<<j)+1)
		rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
	fo(i,1,n)if (s[i]!=')')nxt[i]=s[i]=='('?to[i]+1:(i<n?i+1:0);
	fo(i,1,n)
	if (s[i]!=')'&&!id[i]){
		st[++u]=i;
		start[u]=L*2+1;
		for(int x=i;x&&s[x]!=')';x=nxt[x]){
			be[x]=u;
			id[x]=++L;
			len[u]++;
		}
	}
	fd(i,n,1)
	if (be[i]&&i==st[be[i]]){
		int p=be[i];
		for(int x=i;be[x]==p;x=nxt[x]){
			if (s[x]=='('){
				LL d=0;
				if (s[x+1]!=')'){
					ans.init();
					query(start[be[x+1]],id[x+1],id[x+1]+len[be[x+1]]-1,id[x+1],id[x+1]+len[be[x+1]]-1);
					d=add(ans[0],ans[3]);
				}
				val[id[x]].digit(d);
			}
			else{
				if (s[x]=='*')val[id[x]].multi();
				else{
					if (s[x]=='+')val[id[x]].plus();
					else val[id[x]].digit(s[x]-'0');
				}
			}
		}
	/*	Vector u;
		u.init();
		fo(x,id[st[p]],id[st[p]]+len[p]-1){
			u=u*val[x];
			u.prt();
		}*/
		build(start[p],id[st[p]],id[st[p]]+len[p]-1);
	}
	fo(i,1,n-1){
		wr[i]=wr[i-1];
		if (s[i]=='+'||s[i]=='*'||s[i]=='(')wr[i]+=!((s[i+1]>='0'&&s[i+1]<='9')||s[i+1]=='(');
		else if (s[i]==')')wr[i]+=!(s[i+1]=='+'||s[i+1]=='*'||s[i+1]==')');
		else wr[i]+=(s[i+1]=='(');
	}
	int q=get();
	fo(i,1,q){
		int l=get(),r=get();
		if (l==r){
			if (s[l]>='0'&&s[i]<='9')Ans[i]=s[l]-'0';
			else Ans[i]=-1;
			continue;
		}
		if (getmin(l,r)-pre[l-1]||pre[r]!=pre[l-1]||wr[r-1]-wr[l-1]>0||s[l]=='+'||s[l]=='*'||s[r]=='+'||s[r]=='*'){Ans[i]=-1;continue;}
		qry[r].push_back(make_pair(l,i));
	}
	fo(i,1,n){
		if (be[i])R[be[i]]=id[i];
		for(auto u:qry[i]){
			int x=u.first;
			int p=be[x];
			ans.init();
			query(start[p],id[st[p]],id[st[p]]+len[p]-1,id[x],R[p]);
			Ans[u.second]=add(ans[0],ans[3]);
		}
	}
	fo(i,1,q)printf("%d\n",Ans[i]);
	return 0;
}
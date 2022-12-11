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

const int N = 2e5+5;
const int M = 2e6+5;
const int Mod1 = 971733731;
const int Mod2 = 1e9+9;
const int P = 127;

LL quickmi(LL x,LL tim,LL mo){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

struct haxi{
	LL v1,v2;
	haxi(const LL v1_=0,const LL v2_=0){v1=v1_;v2=v2_;}
	friend bool operator <(haxi a,haxi b){
		return a.v1!=b.v1?a.v1<b.v1:a.v2<b.v2;
	}
};
haxi operator +(haxi a,haxi b){return haxi((a.v1+b.v1)%Mod1,(a.v2+b.v2)%Mod2);}
haxi operator -(haxi a,haxi b){return haxi((a.v1+Mod1-b.v1)%Mod1,(a.v2+Mod2-b.v2)%Mod2);}
haxi operator *(haxi a,haxi b){return haxi(a.v1*b.v1%Mod1,a.v2*b.v2%Mod2);}
haxi operator +(haxi a,int v){return haxi((a.v1+v)%Mod1,(a.v2+v)%Mod2);}
haxi operator *(haxi a,int v){return haxi(a.v1*v%Mod1,a.v2*v%Mod2);}

int n,m;
char s1[N],s2[N];

struct palindrome_tree{
	struct node{
		int son[26];
		int len,fa,pos,to;
	}tree[N];
	int tot,n;
	char a[N];
	int fa[N][20];
	int lim;
	
	void init(){
		tot=2;
		tree[1].len=-1;
		tree[2].len=0;
		tree[2].fa=1;
	}
	
	int key1[N],key2[N];
	
	void build(char *s,int len){
		int now=2;
		n=len;
		fo(i,1,len){
			a[i]=s[i];
			int c=s[i]-'a';
			for(;now&&s[i-tree[now].len-1]!=s[i];now=tree[now].fa);
			if (!tree[now].son[c]){
				int x=tree[now].son[c]=++tot;
				tree[x].pos=i;
				tree[x].len=tree[now].len+2;
				now=tree[now].fa;
				for(;now&&s[i-tree[now].len-1]!=s[i];now=tree[now].fa);
				if (tree[now].son[c])tree[x].fa=tree[now].son[c];
				else tree[x].fa=2;
				int y=tree[x].fa;
				if (tree[x].len-tree[y].len==tree[y].len-tree[tree[y].fa].len)tree[x].to=tree[y].to;
				else tree[x].to=y;
				now=x;
			}
			else now=tree[now].son[c];
			key1[i]=now;
		}
		now=2;
		fd(i,len,1){
			int c=s[i]-'a';
			for(;now&&s[i+tree[now].len+1]!=s[i];now=tree[now].fa);
			now=tree[now].son[c];
			key2[i]=now;
		}
		lim=log(tot)/log(2);
		fo(i,1,tot){
			fa[i][0]=tree[i].fa;
			fo(j,1,lim)fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	
	int jump(int x,int len){
		if (tree[x].len<=len)return x;
		fd(i,lim,0)
		if (tree[fa[x][i]].len>len)x=fa[x][i];
		return fa[x][0];
	}
	
	int double_pal(int l,int r){
		int x=jump(key2[l],r-l),y=jump(key1[r],r-l);
		int ret=0;
		if (x>2)ret=tree[jump(key1[r],r-l+1-tree[x].len)].len==r-l+1-tree[x].len?tree[x].len:0;
		if (y>2&&!ret)ret=tree[jump(key2[l],r-l+1-tree[y].len)].len==r-l+1-tree[y].len?r-l+1-tree[y].len:0;
		return ret;
	}
}PA,PB;
haxi mi[M],ny[M];
haxi pre1[N],pre2[N];
map<haxi,int>cnt;

haxi getsec1(int l,int r){return pre1[r]-pre1[l-1]*mi[r-l+1];}

haxi getsec2(int l,int r){return pre2[r]-pre2[l-1]*mi[r-l+1];}

map<haxi,int>cnta,cntb;
haxi A[N],B[N];
map<haxi,int>ida,idb;

int main(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	PA.init();PA.build(s1,n);
	PB.init();PB.build(s2,m);
	mi[0]=haxi(1,1);
	fo(i,1,1e6)mi[i]=mi[i-1]*P;
	ny[0]=haxi(1,1);
	ny[1]=haxi(quickmi(P,Mod1-2,Mod1),quickmi(P,Mod2-2,Mod2));
	fo(i,2,1e6)ny[i]=ny[i-1]*ny[1];
	fo(i,1,n)pre1[i]=pre1[i-1]*P+s1[i];
	fo(i,1,m)pre2[i]=pre2[i-1]*P+s2[i];
	LL ans=1ll*(PA.tot-2)*(PB.tot-2);
	fo(x,3,PB.tot){
		int wx=PB.tree[x].pos;
		int lenx=PB.tree[x].len;
		haxi hax=getsec2(wx-lenx+1,wx);
		cntb[B[x]=hax]++;
		idb[hax]=x;
		if (PB.tree[x].fa>2){
			int y=PB.tree[x].fa;
			int wy=PB.tree[y].pos;
			int leny=PB.tree[y].len;
			haxi hay=getsec2(wy-leny+1,wy);
			haxi ha=(hax-hay)*ny[leny];
			cnt[ha]++;
		}
	}
	fo(x,3,PA.tot){
		int wx=PA.tree[x].pos;
		int lenx=PA.tree[x].len;
		haxi hax=getsec1(wx-lenx+1,wx);
		cnta[A[x]=hax]++;
		ida[hax]=x;
		if (PA.tree[x].fa>2){
			int y=PA.tree[x].fa;
			int wy=PA.tree[y].pos;
			int leny=PA.tree[y].len;
			haxi hay=getsec1(wy-leny+1,wy);
			haxi ha=hax-hay*mi[lenx-leny];
			ans=ans-cnt[ha];			
		}
	}
	fo(x,3,PA.tot){
		if (PA.tree[x].fa>2){
			int y=PA.tree[x].fa;
			int l=PA.tree[x].pos-PA.tree[x].len+PA.tree[y].len+1,r=PA.tree[x].pos;
			int d=PA.double_pal(l,r);
			if (d){
				haxi h1=getsec1(l,r),h2=getsec1(l,l+d-1);
				h1=h1*mi[d]+h2;
				int p=idb[h1];
				if (PB.tree[PB.tree[p].fa].len>d)ans=ans-cntb[h1];
			}
		}
	}
	fo(x,3,PB.tot){
		if (PB.tree[x].fa>2){
			int y=PB.tree[x].fa;
			int l=PB.tree[x].pos-PB.tree[x].len+1,r=PB.tree[x].pos-PB.tree[y].len;
			int d=PB.double_pal(l,r);
			if (d){
				haxi h1=getsec2(l,r),h2=getsec2(l+d,r);
				h1=h2*mi[r-l+1]+h1;
				int p=ida[h1];
				if (PA.tree[PA.tree[p].fa].len>r-l+1-d)ans=ans-cnta[h1];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
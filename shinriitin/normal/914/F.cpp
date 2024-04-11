#include <bits/stdc++.h>

//#define debug

const int max_N = 1e5 + 21;

const int sqrt_N = 400 + 21;

const int sigma = 26;

#ifdef debug

const int K = 5;

#else

const int K = 400;

#endif

using star = struct node*;

struct node{
	int len,siz;
	star par,trans[sigma];
	void clone(star x,int n){
		siz=0,len=n;
		par=x->par;
		for(int i=0;i<sigma;++i)
			trans[i]=x->trans[i];
		x->par=this;
	}
};

struct sam{
	node pool[sqrt_N<<1];
	star rt,last,tail;
	int cnt[sqrt_N],Q[sqrt_N<<1];
	star append(int c,int n){
		star p,q,r,cur=tail++;
		cur->len=n,cur->siz=1;
		for(int i=0;i<sigma;++i)
			cur->trans[i]=0;
		for(p=last;p&&!p->trans[c];p=p->par)
			p->trans[c]=cur;
		if(!p)cur->par=rt;
		else{
			q=p->trans[c];
			if(p->len+1==q->len)
				cur->par=q;
			else{
				r=tail++;
				r->clone(q,p->len+1);
				for(;p&&p->trans[c]==q;p=p->par)
					p->trans[c]=r;
				cur->par=r;
			}
		}
		return cur;
	}
	void build(char*s,int n){
		tail=pool;
		last=rt=tail++;
		rt->par=0;
		rt->len=rt->siz=0;
		for(int i=0;i<sigma;++i)
			rt->trans[i]=0;
		for(int i=0;i<n;++i){
			last=append(s[i]-'a',i+1);
		}
		for(int i=0;i<=n;++i)cnt[i]=0;
		for(star p=pool;p<tail;++p)++cnt[p->len];
		for(int i=1;i<=n;++i)cnt[i]+=cnt[i-1];
		for(star p=tail-1;p>pool;--p)
			Q[--cnt[p->len]]=p-pool;
		for(int i=tail-pool-1;~i;--i){
			star p=pool+Q[i];
			if(p->par)p->par->siz+=p->siz;
		}
	}
	int count(char*s,int n){
		star p=rt;
		for(int i=0;i<n;++i){
			if(!p->trans[s[i]-'a'])return 0;
			p=p->trans[s[i]-'a'];
		}
		return p->siz;
	}
}SAM[sqrt_N];

int n,m,q,fail[max_N];

char s[max_N],t[max_N];

void get_fail(char*t,int m){
	fail[0]=-1;
	for(int i=1,j;i<m;++i){
		for(j=fail[i-1];~j&&t[j+1]!=t[i];j=fail[j]);
		fail[i]=t[j+1]==t[i]?j+1:-1;
	}
}

int kmp(char*s,int n,char*t,int m){
	int res=0;
	for(int i=0,j=-1;i<n;++i){
		while(~j&&s[i]!=t[j+1])j=fail[j];
		if(s[i]==t[j+1])++j;
		if(j==m-1){
			++res;
			j=fail[j];
		}
	}
	return res;
}

int main(){
#ifdef debug
	freopen("input.txt","r",stdin);
	freopen("main.out","w",stdout);
#endif
	scanf("%s",s);
	n=strlen(s);
	for(int a=0,i=0;a<n;++i,a+=K){
		int b=std::min(a+K,n);
		SAM[i].build(s+a,b-a);
	}
	scanf("%d",&q);
	while(q--){
		int opt,x,l,r; scanf("%d",&opt);
		if(opt==1){
			scanf("%d%s",&x,t);
			s[--x]=t[0];
			int i=x/K,a=i*K,b=std::min(a+K,n);
			SAM[i].build(s+a,b-a);
		}
		else{
			scanf("%d%d%s",&l,&r,t);
			--l,--r;
			get_fail(t,m=strlen(t));
			if(m>K)
				printf("%d\n",kmp(s+l,r-l+1,t,m));
			else{
				int res=0,lx=l/K,rx=r/K;
				for(int i=lx+1;i<rx;++i)
					res+=SAM[i].count(t,m);
				for(int i=lx+2;i<rx;++i){
					int a=i*K-(m-1),b=i*K+(m-1);
					res+=kmp(s+a,b-a,t,m);	
				}
				if(lx+1>=rx)
					res+=kmp(s+l,r-l+1,t,m);
				else{
					int a=(lx+1)*K+(m-1);
					res+=kmp(s+l,a-l,t,m);
					int b=rx*K-(m-1);
					res+=kmp(s+b,r-b+1,t,m);
				}
				printf("%d\n",res);
			}
		}
	}
	return 0;
}
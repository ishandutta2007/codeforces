#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int n;
int a[100010];
int l,r;
int lft[100010];
struct node{
	int col,pos;
	bool operator <(node b){
		return pos<b.pos;
	}
	bool operator >(node b){
		return pos>b.pos;
	}
} s[100010];
struct point{
	int col,pos;
	bool operator <(point b){
		return lft[col]>lft[b.col];
	}
	bool operator >(point b){
		return lft[col]<lft[b.col];
	}
} s1[100010];
int len,len1;
void pushup(int p){
	while(p>1&&s[p>>1]>s[p]){
		swap(s[p],s[p>>1]);p>>=1;
	}
}
void pushdown(int p){
	while(1){
		int l=p<<1;
		if(l>len) break ;
		int r=p<<1|1,t;
		if(r>len) t=l;
		else if(s[l]<s[r]) t=l;
		else t=r;
		if(s[t]<s[p]){
			swap(s[p],s[t]);p=t;
		} 
		else break ;
	}
}
void insert(int x,int y){
	s[++len].col=x,s[len].pos=y;
	pushup(len);
}
void del(){
	s[1]=s[len--];
	pushdown(1);
}
node query(){
	return s[1];
}
void pushup1(int p){
	while(p>1&&s1[p>>1]>s1[p]){
		swap(s1[p],s1[p>>1]);p>>=1;
	}
}
void pushdown1(int p){
	while(1){
		int l=p<<1;
		if(l>len1) break ;
		int r=p<<1|1,t;
		if(r>len1) t=l;
		else if(s1[l]<s1[r]) t=l;
		else t=r;
		if(s1[t]<s1[p]){
			swap(s1[p],s1[t]);p=t;
		} 
		else break ;
	}
}
void insert1(int x,int y){
	s1[++len1].col=x,s1[len1].pos=y;
	pushup1(len1);
}
void del1(){
	s1[1]=s1[len1--];
	pushdown1(1);
}
point query1(){
	return s1[1];
}
bool check(int x){
	while(len>0) del();
	while(len1>0) del1();
	for(int i=1;i<=n;++i){
		if(a[i]!=a[i-1]) lft[a[i]]=0;
		++lft[a[i]];
		if(a[i+1]!=a[i]) insert1(a[i],-x);
	}
	for(int i=1;i<=n;++i){
		node c=query();
		while(len>0&&i-c.pos-1>=x){
			if(lft[c.col])insert1(c.col,c.pos);
			del();
			c=query();
		}
		if(len1<=0) return 0;
		point c1=query1();del1();
		--lft[c1.col];
		if(lft[c1.col]) insert(c1.col,i);
	}
	return 1;
}
int main(){
	T=read();
	while(T--){
		n=read();
		memset(a,-1,sizeof(a));
		for(int i=1;i<=n;++i) a[i]=read();
		sort(a+1,a+n+1);
		l=0,r=n-1;
		int ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)){
				l=mid+1;ans=mid;
			} 
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}
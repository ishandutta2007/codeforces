#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#include<random>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
char str[11];
int q;
int len;
int cnt;
// int mxl[1000010],fail[1000010],tr[1000010][26];
struct node{
	int rgt_occ,sec_rgt_occ;
	int scnt;
	int len,fail;
	int tr[26],pr;
	void update(int occ){
		// printf("%d %d\n",rgt_occ,sec_rgt_occ);
		if(occ>rgt_occ) sec_rgt_occ=rgt_occ,rgt_occ=occ;
		else if(occ>sec_rgt_occ) sec_rgt_occ=occ;
		// printf("%d %d\n",rgt_occ,sec_rgt_occ);
	}
}s[1000010];
int lst;
int st;
int lpp[1000010];
int ns[1000010];
int get_fail(int p){
	while(ns[len-s[p].len-1]!=ns[len]){
		// printf("len:%d,p:%d,slen:%d\n",len,p,s[p].len);
		p=s[p].fail;
	}
	return p;
}
int siz;
void add(int c,int le){
	ns[le]=c;
	int p=get_fail(lst);
	// printf("lst:%d,%d,p:%d %d\n",lst,s[lst].len,p,s[p].fail);
	if(!s[p].tr[c]){
		// printf("new:p:%d\n",p);
		int fa=s[get_fail(s[p].fail)].tr[c];
		// printf("%d %d\n",get_fail(s[p].fail),fa);
		s[p].tr[c]=++cnt;++siz;
		if(fa==0) fa=1;
		s[fa].scnt++;
		s[cnt].fail=fa;s[cnt].len=s[p].len+2;s[cnt].pr=p;
	}
	lst=s[p].tr[c];
	int occ=le-s[lst].len+1;
	// printf("occ:%d\n",occ);
	s[lst].update(occ);
	lpp[occ]=lst;
}
void pop(){
	++st;
	int p=lpp[st];
	if(st+s[p].len-1==len){
		lst=s[lst].fail;
	}
	int f=s[p].fail;
	if(f>1){
		int up=st+s[p].len-s[f].len;
		s[f].update(up);
		if(s[f].len>s[lpp[up]].len) lpp[up]=f;
	}
	// printf("st:%d,p:%d,pr:%d,%d %d\n",st,p,s[p].pr,s[p].rgt_occ,s[p].sec_rgt_occ);
	if(s[p].scnt==0&&s[p].sec_rgt_occ<st){
		--siz;s[s[p].fail].scnt--;s[s[p].pr].tr[ns[st]]=0;
	}ns[st]=-1;
}
int main(){
	memset(ns,-1,sizeof(ns));
	cnt=1;
	s[1].fail=0;s[0].len=-1;s[0].scnt=1;lst=1;
	// for(int i=0;i<26;++i) 
	q=read();
	while(q--){
		scanf("%s",str);
		if(str[1]=='u'){
			char c=getchar();
			while(!isalpha(c)) c=getchar();
			add(c-'a',++len);
		}
		else{
			pop();
		}
		printf("%d\n",siz);
	}
}
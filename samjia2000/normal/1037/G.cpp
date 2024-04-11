#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int N = 1e5+5;

int n,m;
char s[N];
struct section{
	int l,r,c,id;
	section(const int l_=0,const int r_=0,const int c_=0,const int id_=0){l=l_;r=r_;c=c_;id=id_;}
}sec[N*52],tmp[N*52];
int k;
int pc[N][26],nc[N][26];
int pv[N][26],nv[N][26],pre[N];
int w[50];
int cnt[N];
bool bz[30];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n){
		w[s[i]-'a']=i;
		fo(c,0,25)pc[i][c]=w[c];
	}
	fo(i,0,25)w[i]=n+1;
	fd(i,n,1){
		w[s[i]-'a']=i;
		fo(c,0,25)nc[i][c]=w[c];
	}
	fo(i,1,n)
		fo(c,0,25){
			cnt[i-pc[i][c]]++;
			cnt[nc[i][c]-i]++;
		}
	fo(i,1,n)cnt[i]+=cnt[i-1];
	fo(i,1,n){
		fo(c,0,25){
			tmp[cnt[i-pc[i][c]]--]=section(pc[i][c]+1,i,c,i);
			tmp[cnt[nc[i][c]-i]--]=section(i,nc[i][c]-1,c,-i);
			k+=2;
		}
	}
	fo(i,0,n)cnt[i]=0;
	fo(i,1,k)cnt[tmp[i].r]++;
	fo(i,1,n)cnt[i]+=cnt[i-1];
	fd(i,k,1)sec[cnt[tmp[i].r]--]=tmp[i];
	fo(i,1,k){
		section u=sec[i];
		int l=u.l,r=u.r;
		fo(c,0,26)bz[c]=0;
		if(l<=r)
		fo(c,0,25){
			int L=nc[l][c],R=pc[r][c];
			if (L&&R<=n&&L<=R){
				int tmp=pre[R]^pre[L]^pv[r][c]^nv[l][c];
				if (tmp<=26)bz[tmp]=1;
			}
		}
		int ret=0;
		while(bz[ret])ret++;
		if (u.id>0){
			pv[r][u.c]=ret;
			if (r<n&&s[r+1]-'a'==u.c)pre[r+1]=pre[pc[r][u.c]]^ret;
		}
		else nv[l][u.c]=ret;
	}
	m=get();
	fo(cas,1,m){
		int l=get(),r=get();
		fo(c,0,26)bz[c]=0;
		fo(c,0,25){
			int L=nc[l][c],R=pc[r][c];
			if (L<=R){
				int tmp=pre[R]^pre[L]^pv[r][c]^nv[l][c];
				if (tmp<=26)bz[tmp]=1;
			}
		}
		if (bz[0])printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
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
const int mo = 1e9+7;
const int INF = 1e9;

int n,q;
int a[N];
struct block{
	int len,st;
	int val;
	LL sum;
}s[N];
int k;
LL mi[N],ny[N];
struct query{
	int l,r,id;
}qry[N];
int ans[N];

bool cmp(query a,query b){return a.r<b.r;}

int fa[N];

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

void merge(int x){fa[x+1]=x;}

int be[N];
LL ps[N],pre[N];

int main(){
	n=get();q=get();
	fo(i,1,n)a[i]=get();
	mi[0]=ny[0]=1;
	mi[1]=2,ny[1]=(mo+1)/2;
	fo(i,2,n)mi[i]=mi[i-1]*mi[1]%mo,ny[i]=ny[i-1]*ny[1]%mo;
	fo(i,1,n)pre[i]=(pre[i-1]+1ll*(a[i]+mo)%mo*mi[i]%mo)%mo;
	fo(i,1,q){
		qry[i].l=get();qry[i].r=get();
		qry[i].id=i;
	}
	sort(qry+1,qry+1+q,cmp);
	int w=1;
	fo(i,1,n)fa[i]=i;
	fo(i,1,n){
		k++;
		s[k].len=1;
		s[k].st=i;
		s[k].val=a[i];
		s[k].sum=(a[i]+mo)%mo;
		be[i]=k;
		ps[k]=(ps[k-1]+s[k].sum)%mo;
		while(k>1&&s[k].val>0){
			merge(s[k-1].st+s[k-1].len-1);
			LL tmp=s[k].val;
			if (s[k-1].len>30)tmp=INF*2;
			else{
				fo(x,1,s[k-1].len){
					tmp=tmp*2;
					if (tmp>INF*2){tmp=INF*2;break;}
				}
			}
			tmp=tmp+s[k-1].val;
			if (tmp>INF)tmp=INF;
			s[k-1].val=tmp;
			s[k-1].sum=(s[k-1].sum+s[k].sum*mi[s[k-1].len])%mo;
			s[k-1].len+=s[k].len;
			k--;
			ps[k]=(ps[k-1]+s[k].sum)%mo;
		}
		while(w<=q&&qry[w].r==i){
			int id=qry[w].id;
			int l=qry[w].l,r=qry[w].r;
			if (l==r)ans[id]=(a[l]+mo)%mo;
			else{
				l++;
				int L=getfather(l);
				LL tmp=(ps[k]+mo-ps[be[L]])%mo;
				int p=L+s[be[L]].len-1;
				tmp=(tmp+(pre[p]+mo-pre[l-1])%mo*ny[l])%mo;
				ans[id]=(tmp*2+a[l-1]+mo)%mo;
			}
			w++;
		}
	}
	fo(i,1,q)printf("%d\n",ans[i]);
	return 0;
}
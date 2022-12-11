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

const int N = 1e6+5;

int n;
char s[N];
struct element{
	int v,pos;
	element(const int v_=0,const int pos_=0){v=v_;pos=pos_;}
	friend bool operator < (element a,element b){return a.v<b.v;}
}PL[N],GPL[N];
struct triple{
	int st,delt,tot;
	triple(const int st_=0,const int delt_=0,const int tot_=0){st=st_;delt=delt_;tot=tot_;}
}G[N],G1[N],G2[N];
int k;
char a[N],b[N];

element min(element a,element b){return a<b?a:b;}

int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	int l=strlen(a+1);
	n=l*2;
	fo(i,1,n)if (i&1)s[i]=a[(i+1)/2];else s[i]=b[i/2];
	k=0;
	fo(i,0,n)GPL[i]=element(1e9,0);
	fo(w,1,n){
		int k1=0;
		fo(i,1,k)
		if (G[i].st>1&&s[G[i].st-1]==s[w])G1[++k1]=triple(G[i].st-1,G[i].delt,G[i].tot);
		int lst=-w;
		int k2=0;
		fo(i,1,k1){
			if (G1[i].st-lst!=G1[i].delt){
				G2[++k2]=triple(G1[i].st,G1[i].st-lst,1);
				if (G1[i].tot>1)G2[++k2]=triple(G1[i].st+G1[i].delt,G1[i].delt,G1[i].tot-1);
			}
			else G2[++k2]=G1[i];
			lst=G1[i].st+G1[i].delt*(G1[i].tot-1);
		}
		if (s[w-1]==s[w]){
			G2[++k2]=triple(w-1,w-1-lst,1);
			lst=w-1;
		}
		G2[++k2]=triple(w,w-lst,1);
		lst=w;
		
		G[k=1]=G2[1];
		fo(i,2,k2){
			if (G2[i].delt==G[k].delt)G[k].tot+=G2[i].tot;
			else G[++k]=G2[i];
		}
		
		PL[w]=element(1e9,0);
		if (w%2==0){
			if (s[w]==s[w-1])PL[w]=min(PL[w],element(PL[w-2].v,w-2));
		}
		fo(i,1,k){
			int r=G[i].st+(G[i].tot-1)*G[i].delt;
			element v=element(1e9,0);
			if (r&1)v=element(PL[r-1].v+1,r-1);
			if (G[i].tot>1)v=min(v,GPL[G[i].st-G[i].delt]);
			if (G[i].delt<=G[i].st)GPL[G[i].st-G[i].delt]=v;
			if (w%2==0)PL[w]=min(PL[w],v);
		}
	}
	if (PL[n].v>n)printf("-1\n");
	else{
		printf("%d\n",PL[n].v);
		for(int i=n;i;i=PL[i].pos)
		if (i-PL[i].pos>2)printf("%d %d\n",PL[i].pos/2+1,i/2);
	}
	return 0;
}
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
#define se second
#define fi first

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

const int L = 260;

struct character{
	char key;
	char a[1000];
	int len;
}c[L];
bool bz[L],pd[L];
int T;

bool operator <(character a,character b){
	if (a.len!=b.len)return a.len<b.len;
	bool bz=1;
	int len=min(a.len,b.len);
	fo(i,1,len)
	if (a.a[i]!=b.a[i]){
		if (a.a[i]<b.a[i])return 1;
		return 0;
	}
	return 0;
}

int que[300];

void prepare(){
	c[0].key='&';
	c[0].a[1]='!';c[0].a[2]='x';c[0].a[3]='&';c[0].a[4]='x';
	c[0].len=4;
	
	c[255].key='|';
	c[255].a[1]='!';c[255].a[2]='x';c[255].a[3]='|';c[255].a[4]='x';
	c[255].len=4;
	
	c[240].key='x';
	c[240].a[1]='x';
	c[240].len=1;
	
	c[204].key='y';
	c[204].a[1]='y';
	c[204].len=1;
	
	c[170].key='z';
	c[170].a[1]='z';
	c[170].len=1;
	
	bz[0]=bz[255]=bz[204]=bz[240]=bz[170]=1;
	pd[204]=pd[240]=pd[170]=1;
	
	int he=0,ta=3;
	que[1]=240,que[2]=204,que[3]=170;
	while(he!=ta){
		he=he%256+1;
		int j=que[he];
		for(int p=he%256+1;p!=ta%256+1;p=p%256+1)if (c[que[p]].len<c[que[he]].len){swap(que[he],que[p]);j=que[he];}
		{
			int i=255^j;
			character tmp;
				if (c[j].key=='x'||c[j].key=='y'||c[j].key=='z'){
					tmp.len=c[j].len+1;
					fo(u,1,c[j].len)tmp.a[u+1]=c[j].a[u];
					tmp.a[1]='!';
					tmp.key='!';
				}
				else{
					tmp.len=c[j].len+3;
					fo(u,1,c[j].len)tmp.a[u+2]=c[j].a[u];
					tmp.a[1]='!';tmp.a[2]='(';tmp.a[tmp.len]=')';
					tmp.key='!';
				}
			if (!bz[i]||tmp<c[i]){
				bz[i]=1;c[i]=tmp;
				if (!pd[i])pd[que[ta=ta%256+1]=i]=1;
			}
		}
		pd[j]=0;
		fo(q,0,255)
		if (bz[q]){
			int k=q;
			int i=j&k;
					character tmp;
					tmp.len=0;
					if (c[j].key=='&'||c[j].key=='!'||c[j].key=='x'||c[j].key=='y'||c[j].key=='z'){
						tmp.len=c[j].len;
						fo(x,1,c[j].len)tmp.a[x]=c[j].a[x];
					}
					else{
						tmp.len=c[j].len+2;
						fo(x,1,c[j].len)tmp.a[x+1]=c[j].a[x];
						tmp.a[1]='(';tmp.a[tmp.len]=')';
					}
					tmp.a[++tmp.len]=tmp.key='&';
					if (c[k].key=='!'||c[k].key=='x'||c[k].key=='y'||c[k].key=='z'){
						fo(x,1,c[k].len)tmp.a[tmp.len+x]=c[k].a[x];
						tmp.len+=c[k].len;
					}
					else{
						fo(x,1,c[k].len)tmp.a[tmp.len+x+1]=c[k].a[x];
						tmp.a[tmp.len+1]='(';
						tmp.len+=c[k].len+2;
						tmp.a[tmp.len]=')';
					}
					if (tmp.len<=50){
						if (!bz[i]||tmp<c[i]){
							c[i]=tmp,bz[i]=1;
							if (!pd[i])pd[que[ta=ta%256+1]=i]=1;
						}
					}
			i=(j^255)&k;
			tmp.len=0;
					tmp.len=c[j].len+3;
					fo(x,1,c[j].len)tmp.a[x+2]=c[j].a[x];
					tmp.a[1]='!';
					tmp.a[2]='(';tmp.a[tmp.len]=')';
						
					tmp.a[++tmp.len]=tmp.key='&';
					if (c[k].key=='!'||c[k].key=='x'||c[k].key=='y'||c[k].key=='z'){
						fo(x,1,c[k].len)tmp.a[tmp.len+x]=c[k].a[x];
						tmp.len+=c[k].len;
					}
					else{
						fo(x,1,c[k].len)tmp.a[tmp.len+x+1]=c[k].a[x];
						tmp.a[tmp.len+1]='(';
						tmp.len+=c[k].len+2;
						tmp.a[tmp.len]=')';
					}
					if (tmp.len<=50){
						if (!bz[i]||tmp<c[i]){
							c[i]=tmp,bz[i]=1;
							if (!pd[i])pd[que[ta=ta%256+1]=i]=1;
						}
					}
			swap(j,k);
			i=j&k;
					tmp.len=0;
					if (c[j].key=='&'||c[j].key=='!'||c[j].key=='x'||c[j].key=='y'||c[j].key=='z'){
						tmp.len=c[j].len;
						fo(x,1,c[j].len)tmp.a[x]=c[j].a[x];
					}
					else{
						tmp.len=c[j].len+2;
						fo(x,1,c[j].len)tmp.a[x+1]=c[j].a[x];
						tmp.a[1]='(';tmp.a[tmp.len]=')';
					}
					tmp.a[++tmp.len]=tmp.key='&';
					if (c[k].key=='!'||c[k].key=='x'||c[k].key=='y'||c[k].key=='z'){
						fo(x,1,c[k].len)tmp.a[tmp.len+x]=c[k].a[x];
						tmp.len+=c[k].len;
					}
					else{
						fo(x,1,c[k].len)tmp.a[tmp.len+x+1]=c[k].a[x];
						tmp.a[tmp.len+1]='(';
						tmp.len+=c[k].len+2;
						tmp.a[tmp.len]=')';
					}
					if (tmp.len<=50){
						if (!bz[i]||tmp<c[i]){
							c[i]=tmp,bz[i]=1;
							if (!pd[i])pd[que[ta=ta%256+1]=i]=1;
						}
					}
			i=(j^255)&k;
			tmp.len=0;
					tmp.len=c[j].len+3;
					fo(x,1,c[j].len)tmp.a[x+2]=c[j].a[x];
					tmp.a[1]='!';
					tmp.a[2]='(';tmp.a[tmp.len]=')';
						
					tmp.a[++tmp.len]=tmp.key='&';
					if (c[k].key=='!'||c[k].key=='x'||c[k].key=='y'||c[k].key=='z'){
						fo(x,1,c[k].len)tmp.a[tmp.len+x]=c[k].a[x];
						tmp.len+=c[k].len;
					}
					else{
						fo(x,1,c[k].len)tmp.a[tmp.len+x+1]=c[k].a[x];
						tmp.a[tmp.len+1]='(';
						tmp.len+=c[k].len+2;
						tmp.a[tmp.len]=')';
					}
					if (tmp.len<=50){
						if (!bz[i]||tmp<c[i]){
							c[i]=tmp,bz[i]=1;
							if (!pd[i])pd[que[ta=ta%256+1]=i]=1;
						}
					}
			swap(j,k);
			i=j|k;
					tmp.len=0;
						tmp.len=c[j].len;
						fo(x,1,c[j].len)tmp.a[x]=c[j].a[x];
					tmp.a[++tmp.len]=tmp.key='|';
					if (c[k].key!='|'){
						fo(x,1,c[k].len)tmp.a[tmp.len+x]=c[k].a[x];
						tmp.len+=c[k].len;
					}
					else{
						fo(x,1,c[k].len)tmp.a[tmp.len+x+1]=c[k].a[x];
						tmp.a[tmp.len+1]='(';
						tmp.len+=c[k].len+2;
						tmp.a[tmp.len]=')';
					}
					if (tmp.len<=50){
						if (!bz[i]||tmp<c[i]){
							c[i]=tmp,bz[i]=1;
							if (!pd[i])pd[que[ta=ta%256+1]=i]=1;
						}
					}
			swap(j,k);
			
					tmp.len=0;
						tmp.len=c[j].len;
						fo(x,1,c[j].len)tmp.a[x]=c[j].a[x];
					tmp.a[++tmp.len]=tmp.key='|';
					if (c[k].key!='|'){
						fo(x,1,c[k].len)tmp.a[tmp.len+x]=c[k].a[x];
						tmp.len+=c[k].len;
					}
					else{
						fo(x,1,c[k].len)tmp.a[tmp.len+x+1]=c[k].a[x];
						tmp.a[tmp.len+1]='(';
						tmp.len+=c[k].len+2;
						tmp.a[tmp.len]=')';
					}
					if (tmp.len<=50){
						if (!bz[i]||tmp<c[i]){
							c[i]=tmp,bz[i]=1;
							if (!pd[i])pd[que[ta=ta%256+1]=i]=1;
						}
					}
			swap(j,k);
			
		}
	}
}

int main(){
	prepare();
	int T=get();
	for(;T;T--){
		int v=0;
		char s[10];
		scanf("%s",s);
		fo(i,0,7)
		if (s[i]=='1')v=v|(1<<i);
		fo(i,1,c[v].len)putchar(c[v].a[i]);
		putchar('\n');
	}
	return 0;
}
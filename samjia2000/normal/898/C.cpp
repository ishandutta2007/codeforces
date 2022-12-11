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

const int L = 210;

char s[22][L][20];
int tot[22],len[22][L];
struct name{
	char s[20];
	int len;
	friend bool operator < (name a,name b){
		if (a.len!=b.len)return a.len<b.len;
		fo(i,1,a.len)if (a.s[i]!=b.s[i])return a.s[i]<b.s[i];
		return 0;
	}
};
map<name,int>id;
int k;

bool is_suffix(int l1,char *s1,int l2,char *s2){
	if (l2>l1)return 0;
	fo(i,1,l2)
	if (s1[l1-l2+i]!=s2[i])return 0;
	return 1;
}

int main(){
	int n=get();
	fo(i,1,n){
		char tmp[20];
		scanf("%s",tmp+1);
		name p;
		p.len=strlen(tmp+1);
		fo(j,1,p.len)p.s[j]=tmp[j];
		if (!id[p])id[p]=++k;
		int nd=id[p];
		int u=get();
		fo(j,1,u){
			char rd[20];
			scanf("%s",rd+1);
			int l=strlen(rd+1);
			bool pd=1;
			fo(x,1,tot[nd])
			if (!is_suffix(len[nd][x],s[nd][x],l,rd)){
				if (is_suffix(l,rd,len[nd][x],s[nd][x])){
					len[nd][x]=l;
					fo(y,1,l)s[nd][x][y]=rd[y];
					pd=0;
				}
			}
			else pd=0;
			if (pd){
				tot[nd]++;
				len[nd][tot[nd]]=l;
				fo(y,1,l)s[nd][tot[nd]][y]=rd[y];
			}
		}
	}
	printf("%d\n",k);
	for(map<name,int>::iterator h=id.begin();h!=id.end();h++){
		fo(i,1,(*h).first.len)putchar((*h).first.s[i]);putchar(' ');
		int nd=(*h).second;
		printf("%d ",tot[nd]);
		fo(i,1,tot[nd]){fo(j,1,len[nd][i])putchar(s[nd][i][j]);putchar(' ');}
		putchar('\n');
	}
	return 0;
}
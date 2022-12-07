#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,p[1000111][26],e[28],k,kk,q,le[111111],pp[1000111],xx[5000555],zz[1000111],yy[1000111];
char a[1000111],s[10011][33];
bool ne[70111000];

void ad(){
	int g=0;
	for (int i=0;i<26;i++)g=g*2+e[i];
	if (!ne[g])return;
	int e=g%5000011;
	for (int w=xx[e];w;w=pp[w])if (yy[w]==g){
		zz[w]++;
		return;
	}
	yy[++kk]=g;
	zz[kk]=1;
	pp[kk]=xx[e];
	xx[e]=kk;
}

int ff(){
	int g=0;
	for (int i=0;i<26;i++)g=g*2+e[i];
	int e=g%5000011;
	for (int w=xx[e];w;w=pp[w])if (yy[w]==g)return zz[w];
	return 0;
}


int fff(){
	int g=0;
	for (int i=0;i<26;i++)g=g*2+e[i];
	ne[g]=1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	a[n]='+';
	for (int i=0;i<n;i++)a[i]-='a';
	for (int i=0;i<26;i++)p[0][i]=-1;
	p[0][a[0]]=0;
	for (int i=1;i<n;i++){
		for (int j=0;j<26;j++)p[i][j]=p[i-1][j];
		p[i][a[i]]=i;
	}
	scanf("%d\n",&k);
	for (int i=0;i<k;i++){
		gets(s[i]);
		le[i]=strlen(s[i]);
		m0(e);
		for (int j=0;j<le[i];j++)e[s[i][j]-'a']=1;
		fff();
	}
	for (int i=0;i<n;i++){
		m0(e);
		e[a[i]]=1;
		if (a[i]==a[i+1])continue;
		ad();
		int x=i-1;
		while (x!=-1){
			int o=-1,l;
			for (int j=0;j<26;j++)if (!e[j]&&p[x][j]>o)o=p[x][j],l=j;
			if (o==-1)break;
			if (l==a[i+1])break;
			e[l]=1;
			ad();
			x=o-1;
		}
	}
	for (int i=0;i<k;i++){
		m0(e);
		for (int j=0;j<le[i];j++)e[s[i][j]-'a']=1;
		printf("%d\n",ff());
	}
	return 0;
}
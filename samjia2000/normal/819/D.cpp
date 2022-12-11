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

const int N = 2e5+5;

int n;
LL T,S;
int a[N];
set<int>s;

LL gcd(LL x,LL y){return y==0?x:gcd(y,x%y);}

bool ext[N];
int key[N];

int k;
map<int,int>id;
int ans[N];
set<LL>val[N];

void exgcd(LL a,LL b,LL &x,LL &y){
	if (!b){x=1,y=0;return;}
	LL tx,ty;
	exgcd(b,a%b,tx,ty);
	x=ty;
	y=tx-(a/b)*ty;
}

int main(){
	T=get();n=get();
	fo(i,1,n){
		a[i]=get();
		S=S+a[i];
	}
	int w=-a[1];
	fo(i,1,n){
		w=(w+a[i])%T;
		key[i]=w;
		if(s.find(w)==s.end()){
			s.insert(w);
			ext[i]=1;
		}
	}
	if (S%T==0){
		fo(i,1,n){
			if (ext[i])putchar('1');else putchar('0');
			putchar(' ');
		}
		putchar('\n');
		return 0;
	}
	LL g=gcd(S,T);
	LL d=S%T;
	d/=g,T/=g;
	LL inv,tmp;
	exgcd(d,T,inv,tmp);
	inv=(inv%T+T)%T;
	fo(i,1,n)
	if (ext[i]){
		LL x=key[i];
		LL res=x%g;
		if (!id[res])id[res]=++k;
		val[id[res]].insert(((x-res)/g+T)%T*inv%T);
	}
	fo(i,1,n)
	if (ext[i]){
		LL x=key[i];
		LL res=x%g;
		int Id=id[res];
		LL tmp=((x-res)/g+T)%T*inv%T;
		if (val[Id].upper_bound(tmp)!=val[Id].end()){
			ans[i]=(*(val[Id].upper_bound(tmp)))-tmp;
		}
		else ans[i]=(*val[Id].begin())+T-tmp;
	}
	fo(i,1,n)printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}
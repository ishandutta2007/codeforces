#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int,int> pir;
typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

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

const int N = 5e5+5;

int n;
LL all[32];
multiset<int>st[32];

int query(){
	LL sum=0;
	int ret=0;
	fo(i,0,30)
	if(st[i].begin()!=st[i].end()){
		int x=*st[i].begin();
		if (x>sum*2)ret++;
		sum=sum+all[i];
	}
	return ret;
}

int main(){
	seed=958372034;
	n=get();
	int cnt=0;
	fo(i,1,n){
		char op;
		while(op=getchar(),op!='+'&&op!='-');
		int x=get();
		int p=0;
		for(;(1<<(p+1))<=x;p++);
		if (op=='+'){
			st[p].insert(x);
			all[p]+=x;
			cnt++;
		}
		else{
			st[p].erase(st[p].find(x));
			all[p]-=x;
			cnt--;
		}
		printf("%d\n",cnt==0?0:cnt-query());
	}
	return 0;
}
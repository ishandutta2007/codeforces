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
struct node{
	int ty,l,r,val;
}tree[N];
int fa[N];

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

void merge(int x,int y){
	x=getfather(x),y=getfather(y);
	fa[x]=y;
}

void getval(int i){
	if(tree[i].ty==1)return;
	if(tree[i].ty==2){
		getval(tree[i].l);
		tree[i].val=tree[tree[i].l].val^1;
		merge(tree[i].l,i);
		return;
	}
	getval(tree[i].l);
	getval(tree[i].r);
	if(tree[i].ty==3){
		tree[i].val=tree[tree[i].l].val&tree[tree[i].r].val;
		if (tree[i].val)merge(tree[i].l,i),merge(tree[i].r,i);
		else{
			if(tree[tree[i].l].val)merge(tree[i].r,i);
			if(tree[tree[i].r].val)merge(tree[i].l,i);
		}
	}
	if(tree[i].ty==4){
		tree[i].val=tree[tree[i].l].val^tree[tree[i].r].val;
		merge(tree[i].l,i),merge(tree[i].r,i);
	}
	if(tree[i].ty==5){
		tree[i].val=tree[tree[i].l].val|tree[tree[i].r].val;
		if(!tree[i].val)merge(tree[i].l,i),merge(tree[i].r,i);
		else{
			if (!tree[tree[i].l].val)merge(tree[i].r,i);
			if (!tree[tree[i].r].val)merge(tree[i].l,i);
		}
	}
}

int main(){
	n=get();
	fo(i,1,n){
		char s[10];
		scanf("%s",s);
		if (s[0]=='I')tree[i].ty=1,tree[i].val=get();
		if (s[0]=='N')tree[i].ty=2,tree[i].l=get();
		if (s[0]=='A'){
			tree[i].l=get();tree[i].r=get();
			tree[i].ty=3;
		}
		if (s[0]=='X'){
			tree[i].l=get();tree[i].r=get();
			tree[i].ty=4;
		}
		if (s[0]=='O'){
			tree[i].l=get();tree[i].r=get();
			tree[i].ty=5;
		}
	}
	fo(i,1,n)fa[i]=i;
	getval(1);
	fo(i,1,n)
	if (tree[i].ty==1){
		if (getfather(1)==getfather(i))putchar('0'+(tree[1].val^1));
		else putchar(tree[1].val+'0');
	}
	putchar('\n');
	return 0;
}
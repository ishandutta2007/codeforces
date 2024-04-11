#include <bits/stdc++.h>

const int max_N = 3e5 + 21;

using star = struct node*;

struct node{
	int cnt;
	star ch[2];
};

star rt;

void modify(int x,int val){
	star u=rt;
	for(int i=29;~i;--i){
		int c=x>>i&1;
		if(!u->ch[c])u->ch[c]=new node();
		u=u->ch[c];
		u->cnt+=val;
	}
}

int query(int x){
	star u=rt;
	int res=0;
	for(int i=29;~i;--i){
		int c=x>>i&1;
		if(!u->ch[c]||u->ch[c]->cnt==0){
			u=u->ch[c^1];
			res|=1<<i;
		}
		else{
			u=u->ch[c];
		}
	}
	return res;
}

int n,a[max_N],p[max_N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	rt=new node();
	for(int i=1;i<=n;++i){
		scanf("%d",p+i);
		modify(p[i],1);
	}
	for(int i=1;i<=n;++i){
		int ans=query(a[i]);
		printf("%d%c",ans," \n"[i==n]);
		modify(a[i]^ans,-1);
	}
	return 0;
}
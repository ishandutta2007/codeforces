#include<bits/stdc++.h>

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

const int N = 105;

int n,m;
LL Alice,Bob,First,Second;
struct modify{
	int ty,x,v;
	modify(const int ty_=0,const int x_=0,const int v_=0){ty=ty_;x=x_;v=v_;}
}c[100005];
int u;

void ad(int l,int r,int ty){
	c[++u]=modify(ty,l,1);
	c[++u]=modify(ty,r+1,-1);
}

bool cmp(modify a,modify b){return a.x<b.x;}

void add(int A,int B,int C,int v){
	if (!v)return;
	B%=2;
	if (A>0)Alice+=v;
	else{
		if (B){
			if (C)Alice+=v;
			else First+=v;
		}
		else{
			if (C==0)Second+=v;
			else{
				if (C==1)First+=v;
				else Alice+=v;
			}
		}
	}
}

LL v[N];

int main(){
	n=get();m=get();
	fo(i,1,n)cin>>v[i];
	fo(s,3,m*2-1){
		int la=1,ra=m;
		ra=min(ra,(s-1)/2);
		la=max(la,s-m);
		ra=min(ra,s-1);
		u=0;
		fo(i,1,n){
			int x=v[i]%s;
			if (la<=min(x,s-x-1))ad(la,min(ra,min(x,s-x-1)),1);
			if (max(s-x,x/2+1)<=ra)ad(max(la,max(s-x,x/2+1)),ra,2);
			if (max(s-x,la)<=min(x/2,ra))ad(max(s-x,la),min(x/2,ra),3);
		}
		sort(c+1,c+1+u,cmp);
		c[u+1].x=ra+1;
		int A=0,B=0,C=0;
		add(A,B,C,c[1].x-la);
		fo(i,1,u){
			if (c[i].ty==1)A+=c[i].v;
			else if (c[i].ty==2)B+=c[i].v;
				else C+=c[i].v;
			add(A,B,C,c[i+1].x-c[i].x);
		}
	}
	Bob=Alice;
	First*=2;
	Second*=2;
	fo(x,1,m){
		int tot=0;
		fo(i,1,n){
			LL tmp=v[i]/x;
			tot=tot^(tmp&1);
		}
		if (tot)First++;else Second++;
	}
	cout<<Alice<<" "<<Bob<<" "<<First<<" "<<Second<<endl;
	return 0;
}
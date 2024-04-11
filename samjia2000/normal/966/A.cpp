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
const int INF = 1e9;

int n,m,cl,ce,v;
set<int>sl,se;

int calcl(int sx,int sy,int tx,int ty,int w){
	int delt=abs(sx-tx);
	return abs(sy-w)+abs(w-ty)+delt;
}

int calcl(int sx,int sy,int tx,int ty){
	if(!cl)return INF;
	int ret=INF;
	set<int>::iterator h=sl.lower_bound(sy);
	if (h==sl.end()){
		ret=calcl(sx,sy,tx,ty,(*sl.begin()));
		h--;
		ret=min(ret,calcl(sx,sy,tx,ty,*h));
	}
	else{
		ret=calcl(sx,sy,tx,ty,*h);
		if (h==sl.begin()){
			h=sl.end();
			h--;
			ret=min(ret,calcl(sx,sy,tx,ty,*h));
		}
		else{
			h--;
			ret=min(ret,calcl(sx,sy,tx,ty,*h));
		}
	}
	return ret;
}

int calce(int sx,int sy,int tx,int ty,int w){
	int delt=abs(sx-tx);
	return abs(sy-w)+abs(w-ty)+(delt?(delt-1)/v+1:0);
}

int calce(int sx,int sy,int tx,int ty){
	if(!ce)return INF;
	int ret=INF;
	set<int>::iterator h=se.lower_bound(sy);
	if (h==se.end()){
		ret=calce(sx,sy,tx,ty,(*se.begin()));
		h--;
		ret=min(ret,calce(sx,sy,tx,ty,*h));
	}
	else{
		ret=calce(sx,sy,tx,ty,*h);
		if (h==se.begin()){
			h=se.end();
			h--;
			ret=min(ret,calce(sx,sy,tx,ty,*h));
		}
		else{
			h--;
			ret=min(ret,calce(sx,sy,tx,ty,*h));
		}
	}
	return ret;
}


int main(){
	n=get();m=get();cl=get();ce=get();v=get();
	fo(i,1,cl){
		int x=get();
		sl.insert(x);
	}
	fo(i,1,ce){
		int x=get();
		se.insert(x);
	}
	int q=get();
	fo(cas,1,q){
		int sx=get(),sy=get(),tx=get(),ty=get();
		int ans=min(calcl(sx,sy,tx,ty),calce(sx,sy,tx,ty));
		if (sx==tx)ans=min(ans,abs(sy-ty));
		printf("%d\n",ans);
	}
	return 0;
}
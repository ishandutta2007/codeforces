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

int n,q;
struct point{
	int x,y,tot;
	point(const int x_=0,const int y_=0,const int tot_=0){x=x_;y=y_;tot=tot_;}
	friend bool operator <(point a,point b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
};
map<LL,int>id;
map<point,int>ans;
int k;
multiset<point>s[N];

int gcd(int x,int y){return !y?x:gcd(y,x%y);}

void add(int x,int y,int v){
	int g=gcd(x,y);
	x/=g,y/=g;
	ans[point(x,y)]+=v;
}

int main(){
	q=get();
	fo(cas,1,q){
		int ty=get(),x=get(),y=get();
		LL r=1ll*x*x+1ll*y*y;
		if (ty==1){
			if (!id[r])id[r]=++k;
			int now=id[r];
			n++;
			int cnt=0;
			multiset<point>::iterator p=s[now].find(point(x,y));
			if (p!=s[now].end()){
				cnt=(*p).tot;
				point u=*p;
				u.tot++;
				s[now].erase(p);
				s[now].insert(u);
			}
			else{
				s[now].insert(point(x,y,1));
			}
			add(x,y,1);
			for(multiset<point>::iterator h=s[now].begin();h!=s[now].end();h++){
				if ((*h).x==x)continue;
				if (cnt<(*h).tot)add((*h).x+x,(*h).y+y,2);
			}
		}
		if (ty==2){
			if (!id[r])id[r]=++k;
			int now=id[r];
			n--;
			int cnt=0;
			multiset<point>::iterator p=s[now].find(point(x,y));
			cnt=(*p).tot;
			point u=*p;
			u.tot--;
			s[now].erase(p);
			if (u.tot)s[now].insert(u);
			add(x,y,-1);
			for(multiset<point>::iterator h=s[now].begin();h!=s[now].end();h++){
				if ((*h).x==x)continue;
				if (cnt<=(*h).tot)add((*h).x+x,(*h).y+y,-2);
			}
		}
		if (ty==3){
			int g=gcd(x,y);
			x/=g,y/=g;
			int tmp=ans[point(x,y)];
			tmp=n-tmp;
			printf("%d\n",tmp);
		}
		
	}
	return 0;
}
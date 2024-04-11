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

const int N = 200005;

int n,T;
struct problem{
	int v,t,id;
	problem(const int v_=0,const int t_=0,const int id_=0){v=v_;t=t_;id=id_;}
	friend bool operator < (problem a,problem b){return a.v>b.v;}
}a[N];
struct pb{
	int id,t;
	pb(const int id_=0,const int t_=0){id=id_;t=t_;}
	friend bool operator <(pb a,pb b){return a.t!=b.t?a.t<b.t:a.id<b.id;}
};
set<pb>s;

int main(){
	n=get();T=get();
	fo(i,1,n){
		int v=get(),t=get();
		a[i]=problem(v,t,i);
	}
	sort(a+1,a+1+n);
	s.clear();
	int now=0,ans=0,cnt=0,key=0;
	int w=1;
	fd(i,n,1){
		while(w<=n&&a[w].v>=i){
			s.insert(pb(a[w].id,a[w].t));
			cnt++,now+=a[w].t;
			w++;
		}
		while(now>T||cnt>i){
			cnt--;
			set<pb>::iterator h=s.end();
			h--;
			now=now-(*h).t;
			s.erase(h);
		}
		if (cnt>ans){
			ans=cnt;
			key=i;
		}
	}
	printf("%d\n",ans);
	s.clear();
	now=0,cnt=0,w=1;
	fd(i,n,key){
		while(w<=n&&a[w].v>=i){
			s.insert(pb(a[w].id,a[w].t));
			cnt++,now+=a[w].t;
			w++;
		}
		while(now>T||cnt>i){
			cnt--;
			set<pb>::iterator h=s.end();
			h--;
			now=now-(*h).t;
			s.erase(h);
		}
	}
	printf("%d\n",cnt);
	for(set<pb>::iterator h=s.begin();h!=s.end();h++)printf("%d ",(*h).id);
	putchar('\n');
	return 0;
}
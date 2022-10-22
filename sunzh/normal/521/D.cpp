#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define PII pair<int,int> 
#define PID pair<int,double>
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int k;
int n,m;
int a[100010];
PII as[100010];
vector<PII> add[100010];
vector<PID>mul;
bool cmp(PID x,PID y){
	return x.se>y.se;
}
bool cm1(PII x,PII y){
	return x.fi>y.fi;
}
int main(){
	k=read(),n=read(),m=read();
	for(int i=1;i<=k;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		int op=read(),pos=read(),v=read();
		switch(op){
			case 1:{
				as[pos]=max(as[pos],mp(v,i));
				break;
			}
			case 2:{
				add[pos].emplace_back(v,i+n);
				break;
			}
			case 3:{
				mul.emplace_back(i+n+n,1.0*v);
				break;
			}
		}
	}
	for(int i=1;i<=k;++i) if(as[i].fi>a[i]) add[i].emplace_back(as[i].fi-a[i],as[i].se);
	for(int i=1;i<=k;++i){
		sort(add[i].begin(),add[i].end(),cm1);
		double s=1.0*a[i];
		for(auto it:add[i]){
			mul.emplace_back(it.se,(s+it.fi)/s);
			s+=it.fi;
		}
	}
	sort(mul.begin(),mul.end(),cmp);
	int ans=min(m,(int)mul.size());
	print(ans);
	putchar('\n');
	sort(mul.begin(),mul.begin()+ans);
	int cnt=1;
	for(auto it:mul){
		if(cnt>ans) break ;
		while(it.fi>n) it.fi-=n;
		++cnt;print(it.fi);putchar(' ');
	}
	putchar('\n');
	return 0;
}
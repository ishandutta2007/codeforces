#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
int n;
int a[1000010];
double ans[1000010];
deque<pair<double,int> >Q; 
long long sum[1000010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		int st=i;
		pair<double,int>p=make_pair(1.0*a[i],i);
		while(!Q.empty()&&Q.back()>p){
			st=Q.back().second;Q.pop_back();
			p=make_pair(1.0*(sum[i]-sum[st-1])/(i-st+1),st);
		}
		p=make_pair(1.0*(sum[i]-sum[st-1])/(i-st+1),st);
		Q.push_back(p);
	}
	int lst=0;
	while(!Q.empty()){
		pair<double,int>p=Q.front();
		Q.pop_front();
		int nxt=(Q.empty()?n+1:Q.front().second);
		for(int i=p.second;i<nxt;++i) ans[i]=p.first;
	} 
	for(int i=1;i<=n;++i) printf("%.9lf\n",ans[i]);
	return 0;
}
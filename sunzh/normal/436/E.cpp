#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,w;
int a[600010];
priority_queue<PII,vector<PII>,greater<PII> >Q1,Q2;
int ans[300010];
long long Ans;
bool used[600010];
void kill(){
	while(Q1.size()&&used[Q1.top().se]) Q1.pop();
	while(Q2.size()&&used[Q2.top().se]) Q2.pop();
}
int main(){
	n=read(),w=read();
	for(int i=1;i<=n;++i) a[i]=read(),a[i+n]=read();
	for(int i=1;i<=n;++i) Q1.push(mp(a[i],i)),Q2.push(mp(a[i+n],i));
	for(int c=1;c<=w;++c){
		kill();
		int i=Q1.top().se;
		Q1.pop();
		kill();
		if(c==w){
			ans[i>n?i-n:i]++;Ans+=a[i]-(i<=n?0:a[i-n]);used[i]=1;
			// printf("i:%d\n",i);
			if(i<=n) Q1.push(mp(a[i+n]-a[i],i+n));
		}
		else if(Q2.size()&&Q1.top().fi+a[i]-(i<=n?0:a[i-n])>=Q2.top().fi){
			Q1.push(mp(a[i]-(i<=n?0:a[i-n]),i));i=Q2.top().se;Ans+=a[i];used[i]=1;Q2.pop();Q1.push(mp(a[i+n]-a[i],i+n));ans[i>n?i-n:i]++;
			// printf("I:%d\n",i);
		}
		else{
			ans[i>n?i-n:i]++;Ans+=a[i]-(i<=n?0:a[i-n]);used[i]=1;
			// printf("i:%d\n",i);
			if(i<=n) Q1.push(mp(a[i+n]-a[i],i+n));
		}
	}
	printf("%lld\n",Ans);
	for(int i=1;i<=n;++i) printf("%d",ans[i]);
}
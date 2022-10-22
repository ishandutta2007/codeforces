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
int n,m;
priority_queue<int,vector<int>,greater<int> >Q[3010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int p=read(),c=read();
		Q[p].push(c);
	}
	long long ans=1e18;
	long long sum=0;
	for(int i=n;i>=1;--i){
		for(int j=2;j<=m;++j){
			while(Q[j].size()>=i){
				Q[1].push(Q[j].top());sum+=Q[j].top();Q[j].pop();
			}
		}
		long long tmp=0;priority_queue<int,vector<int>,greater<int> >T;
		for(int j=2;j<=m;++j){
			priority_queue<int,vector<int>,greater<int> >a=Q[j];
			while(a.size()){
				T.push(a.top());a.pop();
			}
		}
		int cnt=0;
		while(Q[1].size()+cnt<i){
			++cnt;tmp+=T.top();T.pop();
		}
		ans=min(ans,sum+tmp);
	}
	printf("%lld\n",ans);return 0;
}
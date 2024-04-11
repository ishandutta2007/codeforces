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
// #define mp make_pair
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
int n;
pair<int,int>mp(int x,int y){
	return make_pair(min(x,y),max(x,y));
}
vector<int>query(int p){
	printf("? %d\n",p);fflush(stdout);
	vector<int>ret(n+1,0);
	for(int i=1;i<=n;++i) ret[i]=read();return ret;
}
vector<int>dep;
vector<int>st[2010];
set<PII>St;
int main(){
	n=read();
	dep=query(1);
	for(int i=1;i<=n;++i) st[dep[i]].pb(i);
	for(int i=1;i<=n;++i) if(dep[i]==1) St.insert(mp(1,i));
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i+=2) cnt1+=st[i].size();
	for(int i=2;i<=n;i+=2) cnt2+=st[i].size();
	if(cnt1<cnt2){
		for(int i=1;i<=n;i+=2){
			for(int j:st[i]){
				vector<int>t=query(j);
				for(int l=1;l<=n;++l) if(t[l]==1) St.insert(mp(j,l));
			}
		}
	}
	else{
		for(int i=2;i<=n;i+=2){
			for(int j:st[i]){
				vector<int>t=query(j);
	 			for(int l=1;l<=n;++l) if(t[l]==1) St.insert(mp(j,l));
			}
		}
	}
	printf("!\n");
	for(PII i:St) printf("%d %d\n",i.fi,i.se);fflush(stdout);
}
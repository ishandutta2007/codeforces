#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,Q;
char str[200010];
struct bit{
	int tre[200010];
	bool vis[200010];
	void insert(int x){
		vis[x]=1;
		while(x<=n){
			tre[x]++;
			x+=x&-x;
		}
	}
	void erase(int x){
		if(!vis[x]) return ;
		vis[x]=0;
		while(x<=n){
			tre[x]--;
			x+=x&-x;
		}
	}
	int query(int x){
		int res=0;
		while(x){
			res+=tre[x];x-=x&-x;
		}
		return res;
	}
	int mn(){
		int l=1,r=n,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(query(mid)) r=mid-1,res=mid;
			else l=mid+1;
		}
		return res;
	}
	int mx(){
		int l=1,r=n,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(query(mid)==query(n)) r=mid-1,res=mid;
			else l=mid+1;
		}
		return res;
	}
	int size(){
		return query(n);
	}
	int begin(){
		return 1;
	}
	int end(){
		return query(n)+1;
	}
	int lower_bound(int x){
		return query(x-1)+1;
	}
}R,P,S;
int distance(int x,int y){
	return y-x;
}
void getans(){
	int ans=0;
//	printf("%d %d %d\n",R.size(),P.size(),S.size());
	if(R.size()&&P.size()&&S.size()){
		int rf=R.mn(),rl=R.mx();
		int sf=S.mn(),sl=S.mx();
		int pf=P.mn(),pl=P.mx();
//		printf("%d %d %d %d %d %d\n",rf,rl,sf,sl,pf,pl);
		int it1=R.lower_bound(min(pf,sf));
		ans+=distance(R.begin(),it1);
		int it2=R.lower_bound(max(pl,sl));
		ans+=distance(it2,R.end());
		it1=R.lower_bound(sf);
		it2=R.lower_bound(sl);
		ans+=distance(it1,it2);
		
		
		it1=P.lower_bound(min(rf,sf));
		ans+=distance(P.begin(),it1);
		it2=P.lower_bound(max(rl,sl));
		ans+=distance(it2,P.end());
		it1=P.lower_bound(rf);
		it2=P.lower_bound(rl);
		ans+=distance(it1,it2);
		
		
		it1=S.lower_bound(min(rf,pf));
		ans+=distance(S.begin(),it1);
		it2=S.lower_bound(max(rl,pl));
		ans+=distance(it2,S.end());
		it1=S.lower_bound(pf);
		it2=S.lower_bound(pl);
		ans+=distance(it1,it2);
		
	}
	else{
		if(!R.size()){
			if(S.size()) ans=S.size();
			else ans=P.size();
		}
		else if(!S.size()){
			if(P.size())ans=P.size();else ans=R.size();
		}
		else{
			if(R.size()) ans=R.size();else ans=S.size();
		}
	}
	printf("%d\n",ans);
}
int main(){
	n=read(),Q=read();
	scanf("%s",str+1);
	for(int i=1;i<=n;++i){
		if(str[i]=='R') R.insert(i);
		else if(str[i]=='P') P.insert(i);
		else S.insert(i);
	}
	getans();
	while(Q--){
		int p=read();
		char c=getchar();
		while(c!='R'&&c!='P'&&c!='S') c=getchar();
		R.erase(p);P.erase(p);S.erase(p);
		if(c=='R') R.insert(p);
		else if(c=='P') P.insert(p);
		else S.insert(p);
		getans();
	}
}
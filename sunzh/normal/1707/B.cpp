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
int T,n;
int a[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		a[1]=read();
		set<int>st;
		int cnt0=0,cnt1=0;
		for(int i=2;i<=n;++i){
			a[i]=read();
			if(a[i]==a[i-1]) ++cnt0;
			else if(st.count(a[i]-a[i-1])) ++cnt1;
			else st.insert(a[i]-a[i-1]);
		}
		// int o=1;
		for(int i=1;i<n-1;++i){
			// printf("%d %d\n",cnt0,cnt1);
			set<int>S;
			if(cnt0) st.insert(0);cnt1+=max(0,cnt0-1);
			swap(cnt1,cnt0);cnt1=0;
			// if(st.size()!=n-o) st.insert(0);++o;
			// st.insert(0);
			// for(int i:st) printf("%d ",i);printf("\n");
			auto it=st.begin();
			while(it!=st.end()){
				int a1=(*it);
				++it;
				if(it==st.end()){
					swap(st,S);break ;
				}
				int a2=(*it);
				if(S.count(a2-a1)) ++cnt1;else S.insert(a2-a1);
			}
		}
		printf("%d\n",st.size()?*st.begin():0);
	}
}
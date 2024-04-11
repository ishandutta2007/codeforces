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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
int h[10010];
int stk[10010],top;
vector<PII>vec[10010],vec2[10010];
int Lmx[10010],Rmx[10010];
int pr1[10010];
void getl(int x){
	top=0;stk[0]=0;
	for(int i=1;i<=x;++i){
		while(top&&h[stk[top]]>=h[i]) --top;
		stk[++top]=i;
	}
	for(int i=1;i<=top;++i) vec[x].pb(mp(x-stk[i-1],h[stk[i]]));
}
void getr(int x){
	top=0;stk[0]=n+1;
	for(int i=n;i>=x;--i){
		while(top&&h[stk[top]]>=h[i]) --top;
		stk[++top]=i;
	}
	for(int j=1;j<=top;++j) vec2[x].pb(mp(stk[j-1]-x,h[stk[j]]));
	// Rmx[i]=max(Rmx[i],(stk[j-1]-i)*h[stk[j]]);
}
signed main(){
	// freopen("t.in","r",stdin);
	// freopen("t.ans","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) h[i]=read();
	for(int i=1;i<=n;++i){
		while(top&&h[stk[top]]>=h[i]) --top;
		stk[++top]=i;
		for(int j=1;j<=top;++j) Lmx[i]=max(Lmx[i],(i-stk[j-1])*h[stk[j]]);
	}
	top=0;stk[0]=n+1;
	for(int i=n;i>=1;--i){
		while(top&&h[stk[top]]>=h[i]) --top;
		stk[++top]=i;
		for(int j=1;j<=top;++j) Rmx[i]=max(Rmx[i],(stk[j-1]-i)*h[stk[j]]);
	}
	int ans=0;
	for(int i=n;i>=1;--i) Rmx[i]=max(Rmx[i],Rmx[i+1]);
	for(int i=1;i<=n;++i) Lmx[i]=max(Lmx[i],Lmx[i-1]),ans=max(ans,Lmx[i-1]+Rmx[i]);
	ans=max(ans,Lmx[n]);
	// printf("%lld\n",ans);
	for(int i=1;i<=n;++i){
		int L=i;
		while(L>1&&h[L-1]>=h[i]) --L;
		int R=i;
		while(R<n&&h[R+1]>=h[i]) ++R;
		getl(L);
		getr(R);
		int it=vec2[R].size()-1;
		pr1[0]=((R-L)+vec2[R][0].fi)*vec2[R][0].se;
		for(int j=1;j<vec2[R].size();++j) pr1[j]=max(pr1[j-1],((R-L)+vec2[R][j].fi)*vec2[R][j].se);
		int pmx=0;
		for(PII j:vec[L]){
			while(it>=0&&vec2[R][it].se+j.se>h[i]) --it;
			// if(it<0) break ;
			if(j.se>h[i]) break ;
			// printf("j:%d,%d,it:%d\n",j.fi,j.se,it);
			// if(it>=0) printf("%d,%d\n",vec2[R][it].fi,vec2[R][it].se);
			pmx=max(pmx,((R-L)+j.fi)*j.se);
			ans=max(ans,(it<0?(h[i]-j.se)*(n-L+1):pr1[it])+pmx);
			if(it!=vec2[R].size()-1) ans=max(ans,pmx+(vec2[R][it+1].fi+(R-L))*(h[i]-j.se));
		}
		it=vec[L].size()-1;
		pr1[0]=((R-L)+vec[L][0].fi)*vec[L][0].se;
		for(int j=1;j<vec[L].size();++j) pr1[j]=max(pr1[j-1],((R-L)+vec[L][j].fi)*vec[L][j].se);
		pmx=0;
		// printf("\n\n");
		for(PII j:vec2[R]){
			while(it>=0&&vec[L][it].se+j.se>h[i]) --it;
			// if(it<0) break ;
			if(j.se>h[i]) break ;
			// printf("j:%d,%d,it:%d\n",j.fi,j.se,it);
			// if(it>=0) printf("%d,%d\n",vec[L][it].fi,vec[L][it].se);
			pmx=max(pmx,((R-L)+j.fi)*j.se);
			ans=max(ans,(it<0?(h[i]-j.se)*R:pr1[it])+pmx);
			if(it!=vec2[R].size()-1) ans=max(ans,pmx+(vec[L][it+1].fi+(R-L))*(h[i]-j.se));
		}
		// printf("L:%d,R:%d,ans:%lld\n",L,R,ans);
		// if(n==1000&&ans>10000000){
		// 	printf("%d %d,%d,%d\n",L,R,vec[L].size(),vec2[R].size());
		// }
		// printf("i:%d,%lld\n",i,ans);
		it=0;
		auto get=[&](PII x,int t){
			if(t<0||t>=vec2[R].size()) return (x.fi-1)*min(h[i],x.se)+h[i]*(R-L+1);
			return (x.fi+vec2[R][t].fi-2)*min(h[i],min(x.se,vec2[R][t].se))+h[i]*(R-L+1);
		};
		for(PII j:vec[L]){
			ans=max(ans,get(j,0));
			while(it<vec2[R].size()&&vec2[R][it].se<=j.se) ans=max(ans,get(j,it)),++it;
			ans=max(ans,get(j,it));
		}
		it=0;
		auto get2=[&](PII x,int t){
			if(t<0||t>=vec[L].size()) return (x.fi-1)*min(h[i],x.se)+h[i]*(R-L+1);
			return (x.fi+vec[L][t].fi-2)*min(h[i],min(x.se,vec[L][t].se))+h[i]*(R-L+1);
		};
		for(PII j:vec2[R]){
			ans=max(ans,get2(j,0));
			while(it<vec[L].size()&&vec[L][it].se<=j.se) ans=max(ans,get2(j,it)),++it;
			ans=max(ans,get2(j,it));
		}
		vector<PII>().swap(vec2[R]);
		vector<PII>().swap(vec[L]);
	}
	printf("%lld\n",ans);
}
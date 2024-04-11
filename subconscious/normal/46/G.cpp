#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 10005
using namespace std;
typedef long long ll;
struct ver{
	int x,y;
	ver operator+(ver p){return(ver){x+p.x,y+p.y};}
}v[160005];
ll dis(ver p){return 1ll*p.x*p.x+1ll*p.y*p.y;}
bool cmp(ver x,ver y){return dis(x)<dis(y);}
bool inr(int p){if(v[p].y==0)return v[p].x>0;return v[p].y>0;}
bool cmp_r(int x,int y){
	if(inr(x)==inr(y))return v[x].x*v[y].y-v[x].y*v[y].x>0;
	return inr(x)>inr(y);
}
int ans[10005],top,n,tot,now,tp;ver res,re;bool q;ll ts;
int main(){
	//freopen("emperor.in","r",stdin);
	//freopen("emperor.out","w",stdout);
	for(int i=-199;i<=199;++i)
		for(int j=-199;j<=199;++j)
			if(i||j)v[++tot]=(ver){i,j};
	sort(v+1,v+tot+1,cmp);
	scanf("%d",&n);
	for(tp=1;tp<=tot;++tp){
		if(dis(v[tp])!=dis(v[tp-1]))++now,ts+=dis(v[tp]);
		if(now>n)break;
	}
	ts-=dis(v[tp]);--tp;
	if(ts&1){
		++tp;ts+=dis(v[tp]);
		for(;dis(v[tp+1])==dis(v[tp]);++tp);
		q=1;
	}
	for(;tp;){
		if(q&&!((dis(v[tp])^ts)&1)){for(;dis(v[tp-1])==dis(v[tp]);--tp);--tp;q=0;continue;}
		++top;re=(ver){1000000,1000000};
		do{
			if(dis(re)>dis(res+v[tp]))re=res+v[tp],ans[top]=tp;
			--tp;
		}while(dis(v[tp])==dis(v[tp+1]));
		res=re;
	}
	sort(ans+1,ans+top+1,cmp_r);re=(ver){0,0};
	puts("YES");
	rep(i,top){
		printf("%d %d\n",re.x,re.y);
		re=re+v[ans[i]];
	}
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckyzc
#define y0 fuckcjb
#define x1 fuckjtjl
#define y1 fucksf
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,P=1e9+7,inf=0x3f3f3f3f;
const ld eps=1e-9;
int a[N],n,k;
set<int>mx;
int q[N];
bool cmp(int x,int y){return a[x]>a[y];}
int sol(int heg){
	if(heg<=0)return 0;
	int tim=heg/k;
	return (1ll*(heg+heg-1ll*tim*k)*(tim+1)/2)%P;
}
int main(){
	scanf("%d%d",&n,&k);--k;
	rep(i,n)scanf("%d",a+i);
	mx.clear();mx.insert(0);mx.insert(n+1);
	rep(i,n)q[i]=i;
	sort(q+1,q+n+1,cmp);
	int ans=0;
	rep(i,n){
		int pos=q[i],tim=0;
		int pre,nxt;
		mx.insert(pos);
		auto it=mx.find(pos);--it;pre=*it;
		it=mx.find(pos);++it;nxt=*it;
		if(max(pre+1,pos-k)>min(pos,nxt-k-1))continue;
		tim=(2ll*P+sol(nxt-k-1-pre)-sol(nxt-k-1-pos)-sol(pos-k-1-pre))%P;
		//max(pre+1,pos-i*k)~min(pos,nxt-i*k-1)
		//printf("%d %d\n",a[pos],tim);
		ans=(ans+1ll*a[pos]*tim)%P;
	}
	printf("%d\n",ans);
	return 0;
}
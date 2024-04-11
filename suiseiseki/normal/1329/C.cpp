#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int Maxn=(1<<20);
const int Inf=(1<<30);
pair<int,int> a[Maxn+5];
int final_v[Maxn+5];
bool vis[Maxn+5];
int h,g;
void pull(int id){
	while(a[id]>min(a[id<<1],a[id<<1|1])){
		if(a[id<<1]<a[id<<1|1]){
			swap(a[id<<1],a[id]);
			id<<=1;
		}
		else{
			swap(a[id<<1|1],a[id]);
			id=(id<<1|1);
		}
		if(id>=(1<<h)){
			return;
		}
	}
}
void solve(){
	scanf("%d%d",&h,&g);
	ll ans=0;
	for(int i=1;i<(1<<h);i++){
		vis[i]=0;
		scanf("%d",&a[i].first);
		a[i].second=i;
		final_v[i]=0;
	}
	h--;
	for(int lv=h-1;lv>=0;lv--){
		int ll=(1<<lv);
		int rr=(1<<(lv+1));
		for(int i=ll;i<rr;i++){
			pair<int,int> tmp=a[i];
			int bot=(i<<(h-lv));
			a[i]=a[bot];
			a[bot]=make_pair(Inf,0);
			pull(i);
			if(lv<g){
				int need_mi=max(final_v[i*2],final_v[i*2+1]);
				while(a[i].first<need_mi){
					a[i]=make_pair(Inf,0);
					pull(i);
				}
				ans+=final_v[i]=a[i].first;
				vis[a[i].second]=1;
				a[i]=tmp;
				pull(i);
			}
			else{
				a[bot]=tmp;
			}
		}
	}
	printf("%lld\n",ans);
	bool first_time=1;
	for(int i=(1<<(h+1))-1;i>0;i--){
		if(!vis[i]){
			if(!first_time){
				putchar(' ');
			}
			else{
				first_time=0;
			}
			printf("%d", i);
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
//
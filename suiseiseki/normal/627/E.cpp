#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=3000;
int r,c,n;
int k;
struct Node{
	int x,y;
	friend bool operator <(Node a,Node b){
		if(a.y==b.y){
			return a.x<b.x;
		}
		return a.y<b.y;
	}
}a[Maxn+5],b[Maxn+5];
int len;
vector<int> g[Maxn+5];
int lst[Maxn+5],nxt[Maxn+5];
ll tmp;
int cnt[Maxn+5];
void calc(int x,int k){
	tmp-=b[x].y*cnt[x];
	tmp+=b[lst[x]].y*cnt[x];
	if(lst[x]&&k>1){
		calc(lst[x],k-1);
	}
	if(lst[x]){
		cnt[lst[x]]+=cnt[x];
	}
	cnt[x]=0;
}
int main(){
	scanf("%d%d%d%d",&r,&c,&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n);	
	ll ans=0;
	for(int left=1,right;left<=r;left++){
		right=r;
		for(int i=1;i<=r;i++){
			g[i].clear();
		}
		len=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=left){
				b[++len]=a[i];
				lst[len]=len-1;
				nxt[len]=len+1;
				cnt[len]=0;
				g[b[len].x].push_back(len);
			}
		}
		tmp=0;
		for(int i=1,j=0;i<=c;i++){
			while(j+1<=len&&b[j+1].y<=i){
				j++;
			}
			if(j-k+1>0){
				cnt[j-k+1]++;
				tmp+=b[j-k+1].y;
			}
		}
		ans+=tmp;
		while(right>left){
			for(int i=0;i<(int)g[right].size();i++){
				int u=g[right][i];
				calc(u,k);
				nxt[lst[u]]=nxt[u];
				lst[nxt[u]]=lst[u];
			}
			ans+=tmp;
			right--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
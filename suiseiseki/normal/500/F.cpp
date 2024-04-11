#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define Maxn 4000
#define Maxt 20000
int n,p,q;
vector<pair<int,int> > t[Maxt+5];
struct Dp{
	int f[Maxn+5];
	Dp operator +=(pair<int,int> p){
		for(int i=Maxn;i>=p.first;i--){
			f[i]=max(f[i],f[i-p.first]+p.second);
		}
		return (*this);
	}
}f[Maxn<<1|5];
int cnt;
int left[Maxt+5],right[Maxt+5];
int main(){
	scanf("%d%d",&n,&p);
	int r_c,r_h,r_t;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&r_c,&r_h,&r_t);
		t[r_t].push_back(make_pair(r_c,r_h));
	}
	for(int i=1;i<=Maxt;i+=p){
		for(int j=0;j<p&&i+j<=Maxt;j++){
			if(j){
				right[i+j]=right[i+j-1];
			}
			if(!t[i+j].empty()){
				f[++cnt]=f[right[i+j]];
				right[i+j]=cnt;
				for(int k=0;k<(int)t[i+j].size();k++){
					f[cnt]+=t[i+j][k];
				}
			}
		}
		for(int j=1;j<p&&i-j>0;j++){
			if(j>1){
				left[i-j]=left[i-j+1];
			}
			if(!t[i-j].empty()){
				f[++cnt]=f[left[i-j]];
				left[i-j]=cnt;
				for(int k=0;k<(int)t[i-j].size();k++){
					f[cnt]+=t[i-j][k];
				}
			}
		}
	}
	scanf("%d",&q);
	int ans;
	int a,b;
	while(q--){
		ans=0;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=b;i++){
			ans=max(ans,f[a-p+1>0?left[a-p+1]:0].f[i]+f[right[a]].f[b-i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
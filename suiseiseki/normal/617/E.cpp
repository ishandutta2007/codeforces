#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxb=334;
const int Maxn=100000;
const int Maxv=(1<<20);
int n,m,k;
int num_0[Maxv+5],num_1[Maxv+5];
int a[Maxn+5],s[Maxn+5];
struct Question{
	int l,r;
	int id;
	friend bool operator <(Question a,Question b){
		if((a.l-1)/Maxb==(b.l-1)/Maxb){
			if(((a.l-1)/Maxb)&1){
				return a.r>b.r;
			}
			return a.r<b.r;
		}
		return a.l<b.l;
	}
}qu[Maxn+5];
ll ans[Maxn+5];
ll answer;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&qu[i].l,&qu[i].r);
		qu[i].id=i;
	}
	sort(qu+1,qu+1+m);
	int pos_l=1,pos_r=0;
	for(int i=1;i<=m;i++){
		while(pos_r<qu[i].r){
			pos_r++;
			num_0[s[pos_r-1]]++;
			num_1[s[pos_r]]++;
			answer+=num_0[k^s[pos_r]];
		}
		while(pos_l>qu[i].l){
			pos_l--;
			num_0[s[pos_l-1]]++;
			num_1[s[pos_l]]++;
			answer+=num_1[k^s[pos_l-1]];
		}
		while(pos_r>qu[i].r){
			answer-=num_0[k^s[pos_r]];
			num_0[s[pos_r-1]]--;
			num_1[s[pos_r]]--;
			pos_r--;
		}
		while(pos_l<qu[i].l){
			answer-=num_1[k^s[pos_l-1]];
			num_0[s[pos_l-1]]--;
			num_1[s[pos_l]]--;
			pos_l++;
		}
		ans[qu[i].id]=answer;
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
vector<pii> V,F,VV;
int n,m;
inline bool cmp(const pii &x,const pii &y){
	if(x.first!=y.first) return x.first<y.first;
	return x.second<y.second;
}
void watch(const vector<pii> &x){
	for(int i=0;i<int(x.size());++i){
		printf("%d %d\n",x[i].first,x[i].second);
	}
}
void Expend(int &pre,int nxt,int st,int ed){
	for(int i=0;i<int(V.size());++i){
		V[i].second+=nxt-pre;
		V[i].first=max(V[i].first,nxt-n);
		V[i].second=min(V[i].second,n);
	}
//	watch(V);
	{
		int rsize=0;
		for(int i=1;i<int(V.size());++i){
			if(V[i].first<=V[rsize].second){
				V[rsize].second=V[i].second;
			}
			else{
				V[++rsize]=V[i];
			}
		}
		V.resize(rsize+1);
	}
//	watch(V);
	{
		VV.clear();
		for(int i=0;i<int(V.size());++i){
			while(st<ed&&V[i].first>F[st].second) ++st;
			while(1){
				if(st==ed){
					VV.push_back(V[i]);
					break;
				}
				if(F[st].second>V[i].second){
					VV.push_back(V[i]);
					break;
				}
				else{
					if(F[st].second==V[i].second){
						if(V[i].first!=V[i].second) VV.push_back(mp(V[i].first,V[i].second-1));
						break;
					}
					else if(V[i].first==F[st].second){
						++V[i].first;
						++st;
					}
					else{
						VV.push_back(mp(V[i].first,F[st].second-1));
						V[i].first=F[st].second+1;
						++st;
					}
				}
			}
		}
		swap(V,VV);
	}
//	watch(V);
	pre=nxt;
}
void main2(){
	V.push_back(pii(1,1));
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		F.push_back(mp(x+y,x));
	}
	sort(F.begin(),F.end(),cmp);
	F.resize(unique(F.begin(),F.end())-F.begin());
	int pre=2;
	for(int i=0;i<int(F.size());){
		if(F[i].first==n+n){
			printf("-1\n");
			return;
		}
		int j=i;
		while(j<int(F.size())&&F[j].first==F[i].first) ++j;
		Expend(pre, F[i].first, i, j);
		if(int(V.size())==0){
			printf("-1\n");
			return;
		}
		i=j;
	}
	printf("%d\n",n+n-2);
}
int main(){
	main2();
	int x;
	scanf("%d",&x);
	return 0;
}
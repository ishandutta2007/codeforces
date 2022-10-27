#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int n, a[N];
vector<int> res[N];
vector< vector<int> > ans;
void solve(vector<int> vec){
	if(vec.size()<=1)return;
	//printf("bef "); for(int i=1;i<=n;i++)printf("%d ", a[i]);
	//printf("op "); for(auto x:vec)printf("%d ", x);
	int tot=0, cur=0;
	for(auto x:vec){
		++tot;
		res[tot].clear();
		for(int i=1;i<=x;i++)
			res[tot].push_back(a[++cur]);
	}
	cur=0;
	for(int i=tot;i>=1;i--){
		for(auto x:res[i])
			a[++cur]=x;
	}
	ans.push_back(vec);
	//printf("after ");  for(int i=1;i<=n;i++)printf("%d ", a[i]); printf("\n");
}
int main() {
	//cin >> n;
	//while(1){
		//n=rand()%30+10;
	cin>>n;
		ans.clear();
		for (int i = 1; i <= n; i ++) cin>>a[i];

		//random_shuffle(a+1,a+1+n);
		//printf("n=%d\n", n);
		//for(int i=1;i<=n;i++)printf("%d ", a[i]);printf("\n");
			//cin >> a[i];
		int mxpos;

		for(int i=1;i<=n;i++){
			if(a[i]==n){
				mxpos=i;
			}
		}

		int dir=-1; // -1: 654  +1: 456
		int done=n;

		while(1){
			int need=done-1;if(need==0)break;

			int pos_need=0, pos_n=0, pos_done=0;
			for(int j=1;j<=n;j++)if(a[j]==need){
				pos_need=j; break;
			}
			for(int j=1;j<=n;j++)if(a[j]==n){
				pos_n=j; break;
			}
			for(int j=1;j<=n;j++)if(a[j]==done){
				pos_done=j; break;
			}
			//printf("pos_need=%d,pos_done=%d,pos_n=%d,dir=%d\n", pos_need,pos_done,pos_n,dir);
			if(dir==-1){
				if(pos_need<pos_n){
					vector<int> tmp; tmp.clear();
					if(pos_need>1) tmp.push_back(pos_need-1);
					tmp.push_back(1);
					tmp.push_back(pos_done-pos_need);
					if(pos_done!=n) tmp.push_back(n-pos_done);
					solve(tmp);
				}else{
					vector<int> tmp; tmp.clear();
					if(pos_n>1) tmp.push_back(pos_n-1);
					for(int j=1;j<=pos_done-pos_n+1;j++) tmp.push_back(1);
					tmp.push_back(pos_need-pos_done);
					if(pos_need!=n) tmp.push_back(n-pos_need);
					solve(tmp);
					dir=1;
				}
			} else {
				if(pos_n<pos_need){
					vector<int> tmp; tmp.clear();
					if(pos_done>1) tmp.push_back(pos_done-1);
					tmp.push_back(pos_n-pos_done+1);
					tmp.push_back(pos_need-pos_n);
					if(pos_need<n)tmp.push_back(n-pos_need);
					solve(tmp);
				}else{
					vector<int> tmp; tmp.clear();
					if(pos_need>1) tmp.push_back(pos_need-1);
					tmp.push_back(pos_done-pos_need);
					for(int j=1;j<=pos_n-pos_done+1;j++) tmp.push_back(1);
					if(pos_n!=n) tmp.push_back(n-pos_n);
					solve(tmp);
					dir=-1;
				}
			}	

			--done;

		}
		if(dir==-1){
			vector<int> tmp;tmp.clear();
			//printf("n=%d\n", n);
			for(int i=1;i<=n;i++)tmp.push_back(1);
			solve(tmp);
		}
		for(int i=1;i<=n;i++)assert(a[i]==i);
		printf("%d\n", ans.size());
		assert(ans.size()<=n);
		for(auto p:ans){
			printf("%d ", p.size());
			int s=0;
			for(auto x:p){
				printf("%d ", x);
				assert(x>0); s+=x;
			}
			assert(s==n);
			printf("\n");
		}
	//}
}
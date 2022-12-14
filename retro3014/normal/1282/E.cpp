#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 100000;

int T, N;
int arr[MAX_N+1][3];
int f[MAX_N*3+10];
vector<pair<pii, int> > vt;
vector<int> ans1, ans2;
int d[MAX_N+1];
vector<int> v;

void pro(int idx, int x, int y){

	int xx, yy, zz;
	int z;
	for(int i=0; i<3; i++){
		if(arr[idx][i]!=x && arr[idx][i]!=y){
			z = arr[idx][i];
			zz = i;
		}
		if(arr[idx][i]==x)	xx = i;
		if(arr[idx][i]==y)	yy = i;
	}
	//cout<<idx<<" "<<x<<" "<<y<<" "<<f[idx*3+3-xx-zz]<<" "<<f[idx*3+3-zz-yy]<<endl;
	if(f[idx*3+3-xx-zz]==0){
		ans1.pb(z);
	}else{
		pro(f[idx*3+3-xx-zz]/3, x, z);
	}
	if(f[idx*3+3-zz-yy]==0){
		ans1.pb(y);
	}else{
		pro(f[idx*3+3-zz-yy]/3, z, y);
	}

}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=1; i<=N-2; i++){
			scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
			for(int j=0; j<3; j++){
				vt.pb({{min(arr[i][j], arr[i][(j+1)%3]), max(arr[i][j], arr[i][(j+1)%3])}, i*3+(j+2)%3});
			}
		}
		sort(vt.begin(), vt.end());
		for(int i=0; i<vt.size()-1; i++){
			if(vt[i].first==vt[i+1].first){
				f[vt[i].second] = vt[i+1].second;
				f[vt[i+1].second] = vt[i].second;
				d[vt[i].second/3]++; d[vt[i+1].second/3]++;
				//cout<<vt[i+1].second/3<<" "<<vt[i].second/3<<endl;
				i++;
			}
		}
		for(int i=1; i<=N-2; i++){
			if(d[i]==1){
				v.pb(i);
			}
		}
		for(int i=0; i<3; i++){
			if(f[3+i]==0){
				ans1.pb(arr[1][(i+2)%3]);
			}else{
				pro(f[3+i]/3, arr[1][(i+1)%3], arr[1][(i+2)%3]);
			}
		}
		while(!v.empty()){
			int n = v.back(); v.pop_back();
			ans2.pb(n);
			for(int i=0; i<3; i++){
				if(f[n*3+i]!=0){
					d[f[n*3+i]/3]--;
					if(d[f[n*3+i]/3]==1){
						v.pb(f[n*3+i]/3);
					}
				}
			}
		}
		for(int i=0; i<ans1.size(); i++){
			printf("%d ", ans1[i]);
		}
		printf("\n");
		for(int i=0; i<ans2.size(); i++){
			printf("%d ", ans2[i]);
		}
		if(N==3){
			printf("1");
		}
		printf("\n");
		while(!ans1.empty())	ans1.pop_back();
		while(!ans2.empty())	ans2.pop_back();
		while(!vt.empty())	vt.pop_back();
		for(int i=1; i<=N-2; i++){
			f[i*3] = f[i*3+1] = f[i*3+2] = 0;
		}
	}
	return 0;
}
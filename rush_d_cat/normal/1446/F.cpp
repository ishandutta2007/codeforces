#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
const double eps = 1e-9;
const double pi = acos(-1);

typedef long long LL;
int n; LL k;
struct Vec {
	int x, y;
	double d(){
		return x*x + y*y;
	}
} p[N];


vector<double> v;
int id(double x) {
	return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
int bit[N];
void add(int x, int k) {
	while(x<N){
		bit[x]+=k; x+=x&(-x);
	}
}
int sum(int x){
	int ans=0;
	while(x>0){
		ans += bit[x]; x -= x&(-x);
	}
	return ans;
}
LL cal(vector< pair<double, double> > vec) {
	memset(bit,0,sizeof(bit));
	sort(vec.begin(),vec.end());
	v.clear();
	for(auto p: vec) {
		v.push_back(p.first); v.push_back(p.second);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	LL res=0;
	for(auto p: vec) {
		res+=sum(id(p.second)) - sum(id(p.first));
		add(id(p.second), 1);
	}
	return res;
}
double check(double x){
	vector< pair<double, double> > vec;
	LL tot=1LL*n*(n-1)/2, cnt=0;

	for(int i=1;i<=n;i++){
		if(p[i].d() > x*x - eps) {
			double dis = sqrt(p[i].d());
			double theta = acos(x / dis);
			double mid = atan2(p[i].y, p[i].x);
			// printf("dis=%.5f,theta=%.5f,mid=%.5f\n", dis,theta,mid);
			int pre = vec.size();
			if (mid < 0) mid += 2 * pi;
			if (mid + theta > 2 * pi) {
				vec.push_back( make_pair(mid + theta - 2 * pi, mid - theta) );
			}else if(mid - theta < 0){
				vec.push_back( make_pair(mid + theta, mid - theta + 2 * pi) );
			}else{
				vec.push_back( make_pair(mid - theta, mid + theta) );
			}
			int cur = vec.size();
			//for (int j = pre; j < cur; j ++) 
			//	printf("[%.5f, %.5f]", vec[j].first, vec[j].second);
			//printf("\n");
		}
	}
	tot -= cal(vec);
	//printf("tot=%lld\n", tot);
	return tot >= k;
}
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	//check(0.7); return 0;
	double lef=0,rig=2e4;
	while(clock() <= 7 * CLOCKS_PER_SEC){
		double mid=(lef+rig)/2;
		//printf("check %.5f\n", mid);
		if(check(mid)) rig=mid; else lef=mid;
	}
	printf("%.8f\n", rig);
}
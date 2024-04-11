#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<pii> v1;
vector<int> v2;
vector<pair<pii, int> > vt1, vt2;

vector<pair<pii, int> > ans;

int main(){
	scanf("%d", &N);
	ll sum = 0;
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x); v1.pb({x, i+1});
		sum+=(ll)x;
	}
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		v2.pb(x);
		sum-=(ll)x;
	}
	if(sum!=0){
		printf("NO");return 0;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(int i=0; i<N; i++){
		if(v1[i].first-v2[i]<0){
			vt1.pb({{v1[i].first, v1[i].first-v2[i]}, v1[i].second});
		}else if(v1[i].first-v2[i]>0){
			vt2.pb({{v1[i].first, v1[i].first-v2[i]}, v1[i].second});
		}
	}
	int s1 = 0, s2 = 0;
	while(s1<vt1.size() && s2<vt2.size()){
		if(vt2[s2].first.first<=vt1[s1].first.first){
			printf("NO");
			return 0;
		}
		if(-vt1[s1].first.second<vt2[s2].first.second){
			int t = -vt1[s1].first.second;
			vt2[s2].first.second-=t;
			vt2[s2].first.first-=t;
			ans.pb({{vt1[s1].second, vt2[s2].second}, t});
			s1++;
		}else{
			int t = vt2[s2].first.second;
			vt1[s1].first.second+=t;
			vt1[s1].first.first+=t;
			ans.pb({{vt1[s1].second, vt2[s2].second}, t});
			s2++;
		}
	}
	printf("YES\n%d\n", ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
	}
	return 0;
}
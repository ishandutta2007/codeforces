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
const int MAX_N = 1;

int T;
int N;
vector<int> a, b;

int main(){
	scanf("%d", &T);
	while(T--){
		while(!a.empty())	a.pop_back();
		while(!b.empty())	b.pop_back();
		scanf("%d", &N);
		int c1 = 0, c2 = 0;
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			a.pb(x);
			if(x==-1)	c1++;
			if(x==1)	c2++;
		}
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			b.pb(x);
		}
		bool tf = true;
		for(int i=N-1; i>=0; i--){
			if(a[i]==-1)	c1--;
			else if(a[i]==1)	c2--;
			if(a[i]<b[i]){
				if(c2==0)	tf = false;
			}else if(a[i]>b[i]){
				if(c1==0)	tf = false;
			}
		}
		if(tf){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
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
const int MAX_N = 200000;

int T;
int N;
string str;
int ans1[MAX_N+1], ans2[MAX_N+1];

vector<pii> vt;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		cin>>str;
		while(!vt.empty())	vt.pop_back();
		int sz = 1;
		for(int i=1; i<str.size(); i++){
			if(str[i]==str[i-1]){
				sz++;
			}else{
				if(str[i-1]=='<'){
					vt.pb({1, sz});
				}else{
					vt.pb({2, sz});
				}
				sz = 1;
			}
		}
		if(str[N-2]=='<'){
			vt.pb({1, sz});
		}else{
			vt.pb({2, sz});
		}
		int S = -1, E = 1;
		ans1[1] = 0;
		ans2[1] = 0;
		int idx = 2, idx2 = 2;
		for(pii i : vt){
			//cout<<i.first<<" "<<i.second<<endl;
			idx2 = idx;
			if(i.first==1){
				ans1[idx-1] = S+1-i.second;
				for(int j=1; j<=i.second; j++){
					ans1[idx] = S+1-i.second+j;
					idx++;
				}
				S = S - i.second;
				idx = idx2;
				for(int j=1; j<=i.second; j++){
					ans2[idx] = E;
					E++;
					idx++;
				}
			}else{
				for(int j=1; j<=i.second; j++){
					ans1[idx] = S;
					S--;
					idx++;
				}
				idx = idx2;
				ans2[idx-1] = E-1+i.second;
				for(int j=1; j<=i.second; j++){
					ans2[idx] = E-1+i.second-j;
					idx++;
				}
				E = E + i.second;
			}
		}
		for(int i=1; i<=N; i++){
			ans1[i]-=S;
			ans2[i]+=(N-E+1);
		}
		for(int i=1; i<=N; i++){
			printf("%d ", ans1[i]);
		}printf("\n");
		for(int i=1; i<=N; i++){
			printf("%d ", ans2[i]);
		}printf("\n");
	}
	return 0;
}
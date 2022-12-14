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
const int MAX_K = 30;

int T;
string str;
vector<int> vt[MAX_K+1];

bool tf = true;
bool vst[MAX_K+1];
vector<int> v;

void dfs(int x){
	vst[x] = true;
	v.pb(x);
	for(int i : vt[x]){
		if(!vst[i]){
			dfs(i);
		}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		tf = true;
		cin>>str;
		while(!v.empty())	v.pop_back();
		for(int i=0; i<='z'-'a'; i++){
			while(!vt[i].empty())	vt[i].pop_back();
		}
		for(int i=0; i<str.size()-1; i++){
			char c1 = str[i], c2 = str[i+1];
			vt[c2-'a'].pb(c1-'a');
			vt[c1-'a'].pb(c2-'a');
		}
		int x=-1, y=-1;
		for(int i=0; i<='z'-'a'; i++){
			sort(vt[i].begin(), vt[i].end());
			vt[i].erase(unique(vt[i].begin(), vt[i].end()), vt[i].end());
			if(vt[i].size()>2){
				tf = false;
				break;
			}
			if(vt[i].size()==0){
				v.pb(i);
			}else if(vt[i].size()==1){
				if(x==-1){
					x = i;
				}else if(y==-1){
					y = i;
				}else{
					tf = false;
					break;
				}
			}
			vst[i] = false;
		}
		if(!tf){
			printf("NO\n");
			continue;
		}
		if(v.size()==26){
			printf("YES\n");
			for(int i : v){
				printf("%c", (char)(i+'a'));
			}
			printf("\n");
			continue;
		}
		if(x==-1 || y==-1){
			printf("NO\n");
			continue;
		}
		dfs(x);
		if(v.size()!=26){
			printf("NO\n");
			continue;
		}else{
			printf("YES\n");
			for(int i : v){
				printf("%c", (char)(i+'a'));
			}
			printf("\n");
			continue;
		}
	}
	return 0;
}
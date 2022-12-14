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
int cnt, c1, c0;
string str;
vector<int> len;

int main(){
	cin>>T;
	while(T--){
		scanf("%d", &N);
		cnt = c1 = c0 = 0;
		while(!len.empty())	len.pop_back();
		for(int k=0; k<N; k++){
			cin>>str;
			len.pb(str.size());
			for(int i=0; i<str.size(); i++){
				if(str[i]=='0'){
					c0++;
				}else{
					c1++;
				}
			}
			if(str.size()%2)	cnt++;
		}
		sort(len.begin(), len.end());
		if(cnt>0 && (c1%2)){
			cnt--;
			c1--;
		}
		if(cnt>0 && (c0%2)){
			cnt--;
			c0--;
		}
		if(cnt%2){
			printf("%d\n", N-1);
		}else if(cnt==0 && ((c1%2) || (c0%2))){
			printf("%d\n", N-1);
		}else{
			printf("%d\n", N);
		}
	}

	return 0;
}
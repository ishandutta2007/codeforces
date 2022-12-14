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
const int MAX_N = 100;

int T;
int R, C, K;
string str[MAX_N+1];
string ans[MAX_N+1];

char getc(int x){
	if(x<10){
		return (char)('0' + x);
	}else if(x <= 10 + 'z'-'a'){
		return (char)('a' + x - 10);
	}else{
		return (char)('A' + x - 36);
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		int sum = 0;
		scanf("%d%d%d", &R, &C, &K);
		for(int i=0; i<R; i++){
			cin>>str[i];
			ans[i] = str[i];
			for(int j=0; j<C; j++){
				if(str[i][j]=='R'){
					sum++;
				}
			}
		}
		int t = sum/K;
		int r = K - (sum % K);
		int x = -1, y = 0;
		int d = 1;
		int num = 0;
		int s = 0;
		while(1){
			if(x+d>=R || x+d<0){
				y++;
				d = -d;
				if(y==C)	break;
			}else{
				x+=d;
			}
			ans[x][y] = getc(num);
			if(str[x][y]=='R'){
				s++;
			}
			if((s==t && r>0) || (s==t+1)){
				if(s==t){
					r--;
				}
				if(num!=K-1){
					num++;
				}
				s = 0;
			}
		}
		for(int i=0; i<R; i++){
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}
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
const int MAX_N = 20;

int T;
int H, W;
int ans[MAX_N+1][MAX_N+1];
int dx[4]={0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool is_in(int x, int y){
	return (x>=1 && x<=H && y>=1 && y<=W);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &H, &W);
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				ans[i][j] = 0;
			}
		}
		int x = 1, y = 1, idx = 0, cnt = 2;;
		ans[1][1] = 1;
		while(1){
			if(is_in(x+dx[idx], y+dy[idx])){
				x+=dx[idx], y+=dy[idx];
				cnt--;
			}else{
				if(idx==3)	break;
				idx++;
			}
			if(cnt==0){
				if(x==2 && y==1)	break;
				cnt = 2;
				ans[x][y] = 1;
				if((x==1 && y==W-1) || (x==H-1 && y==W) || (x==H && y==2)){
					cnt++;
				}
			}
		}
		for(int i=1 ;i<=H; i++){
			for(int j=1; j<=W; j++){
				printf("%d", ans[i][j]);
			}printf("\n");
		}
		printf("\n");
	}
	return 0;
}
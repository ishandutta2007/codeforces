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
#define test 0
#define TEST if(test)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 10;
const int MAX_M = 52;
const int MAX_K = (1<<10)+10;

int dp[MAX_M+1][MAX_K+1];
bool vst[MAX_M+1][MAX_K+1];

int from[MAX_M+1][MAX_K+1];
int T, N;
string str[12];
int idx[MAX_N+1][MAX_M+1][2];

int tnum(char c){
	if('a'<=c && c<='z'){
		return c-'a';
	}else{
		return ('z'-'a'+1)+(c-'A');
	}
}

char tchar(int x){
	if(x<26){
		return 'a'+x;
	}else{
		return 'A'+(x-26);
	}
}

int id[MAX_N+1];

int calc_ny(int x, int y, int x2){
	if(x==x2){
		if(y==(1<<N)-1){
			return 0;
		}else{
			return -1;
		}
	}
	int ty = y;
	for(int i=0; i<N; i++){
		id[i] = idx[i][x][ty%2];
		ty/=2;
	}
	int ret = 0, two = 1;
	for(int i=0; i<N; i++){
		if(idx[i][x2][0]==-1 || idx[i][x2][0]>id[i]){
			return -1;
		}
		if(idx[i][x2][1]!=-1 && idx[i][x2][1]<id[i])	ret+=two;
		two*=2;
	}
	return ret;
}

int getdp(int x, int y){
	if(x>=MAX_M)	return -1;
	if(vst[x][y])	return dp[x][y];
	vst[x][y] = true;
	int ty = y;
	for(int i=0; i<N; i++){
		if(idx[i][x][ty%2]==-1){
			dp[x][y] = -1;
			return -1;
		}
		ty/=2;
	}
	dp[x][y] = 1;
	TEST cout<<"!"<<tchar(x)<<" "<<y<<endl;
	for(int i=0; i<MAX_M; i++){
		int ny = calc_ny(x, y, i);
		if(ny!=-1){
			int ndp = getdp(i, ny);
			TEST cout<<tchar(i)<<" "<<ndp<<" "<<ny<<endl;
			if(ndp+1 > dp[x][y]){
				dp[x][y] = ndp+1;
				from[x][y] = i;
			}
		}
	}
	ty = y;
	for(int i=0; i<N; i++){
		if(ty%2){
			ty = y - (1<<i);
			int ndp = getdp(x, ty);
			if(ndp>dp[x][y]){
				dp[x][y] = ndp;
				from[x][y] = from[x][ty];
			}
			break;
		}
		ty/=2;
	}
	TEST cout<<"*"<<dp[x][y]<<" "<<tchar(from[x][y])<<endl;
	return dp[x][y];
}

vector<char> ans;

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0; i<N; i++){
			cin>>str[i];
			for(int j=0; j<MAX_M; j++){
				idx[i][j][0] = idx[i][j][1] = -1;
			}
			for(int j=0; j<(int)str[i].size(); j++){
				int n = tnum(str[i][j]);
				if(idx[i][n][0]==-1){
					idx[i][n][0] = j;
				}else{
					idx[i][n][1] = j;
					TEST cout<<tchar(n)<<" "<<i<<endl;
				}
			}
		}
		for(int i=0; i<MAX_M; i++){
			for(int j=0; j<(1<<N); j++){
				vst[i][j] = false;
				dp[i][j] = -1;
			}
		}
		int mx = 0;
		int idx1, idx2;
		for(int i=0; i<MAX_M; i++){
			for(int j=0; j<(1<<N); j++){
				int t = getdp(i, j);
				if(t>mx){
					TEST cout<<i<<" "<<j<<" "<<t<<endl;
					mx = t;
					idx1 = i; idx2 = j;
				}
			}
		}
		while(mx!=0){
			ans.pb(tchar(idx1));
			if(dp[idx1][idx2]==1)	break;
			int nidx1 = from[idx1][idx2];
			idx2 = calc_ny(idx1, idx2, nidx1);
			idx1 = nidx1;
		}
		cout<<(int)ans.size()<<"\n";
		while(!ans.empty()){
			cout<<ans.back();
			ans.pop_back();
		}
		cout<<"\n";
	}
	return 0;
}
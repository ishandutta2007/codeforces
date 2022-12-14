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
const int MAX_N = 2048;
const int MAX_K = 11;
const int MAX_Q1 = 30;

int N;

int rnd(){
	return (rand()%N)+1;
}

int idx[MAX_K+1];
int ans[MAX_N+1];

int query(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

void answer(){
	printf("! ");
	for(int i=1; i<=N; i++){
		printf("%d ", ans[i]);
	}
	fflush(stdout);
}

vector<int> v;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=MAX_Q1; i++){
		int a = rnd(), b = rnd();
		while(a==b){
			b = rnd();
		}
		int x = query(a, b);
		for(int j=0; j<MAX_K; j++){
			if((x & (1<<j))==0){
				idx[j] = a;				
			}
		}
	}
	for(int i=1; i<=N; i++)	v.pb(i);
	random_shuffle(v.begin(), v.end());
	int n = 0;
	int z;
	
	for(int i : v){
		//cout<<i<<endl;
		bool tf = false;
		if(i==idx[n])	tf = true;
		else{
			int x = query(i, idx[n]);
			if((x & ((1<<(n+1))-1))==0){
				tf = true;
			}
		}
		if(tf){
			idx[n] = i;
			while(n+1<MAX_K){
				if(i==idx[n+1]){
					n++;
					continue;
				}
				int x = query(i, idx[n+1]);
				if((x & (1<<(n+1)))==0){
					n++;
					idx[n] = i;
				}else 	break;
			}
			if(n==MAX_K-1){
				z = i;
				break;
			}
		}
	}
	for(int i=1; i<=N; i++){
		if(i==z){
			ans[i] = 0;
		}else{
			ans[i] = query(i, z);
		}
	}
	answer();
	return 0;
}
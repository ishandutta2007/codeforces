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

int N;
string str;
int cnt[10];

void chk1(){
	printf("red\n");
}
void chk2(){
	printf("cyan\n");
}

int main(){
	scanf("%d", &N);
	while(N--){
		cin>>str;
		for(int i=0; i<10; i++)	cnt[i] = 0;
		for(int i=0; i<str.size(); i++){
			cnt[str[i]-'0']++;
		}
		bool tf = true;
		for(int j=1; j<10; j++){
			if(cnt[j]!=0){
				tf = false;
				break;
			}
		}
		if(tf){
			chk1();
			continue;
		}
		tf = false;
		if(cnt[0]==0){
			chk2();
			continue;
		}
		cnt[0]--;
		for(int j=0; j<10; j+=2){
			if(cnt[j]!=0){
				tf = true; break;
			}
		}
		if(!tf){
			chk2();
			continue;
		}
		int sum = 0;
		for(int j=1; j<10; j++){
			sum += j * cnt[j];
		}
		if(sum%3==0){
			chk1();
		}else	chk2();
	}
	return 0;
}
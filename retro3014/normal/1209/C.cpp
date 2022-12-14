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
const int MAX_K = 100;

int T;
int N;
string str;
pii pos[MAX_K+1];
set<int> st[MAX_K+1];

int main(){
	cin>>T;
	while(T--){
		scanf("%d", &N);
		cin>>str;
		for(int i=0; i<=9; i++){
			st[i].clear();
			pos[i].first = INF;
			pos[i].second = 0;
		}
		for(int i=0; i<N; i++){
			int k = (int)(str[i]-'0');
			pos[k].first = min(pos[k].first, i);
			pos[k].second = max(pos[k].second, i);
			st[k].insert(i);
		}
		bool tf = true;
		for(int i=0; i<10; i++){
			tf = true;
			int t = 0;
			int i1 = INF, i2 = -1;
			for(int j=0; j<i; j++){
				if(pos[j].first==INF)	continue;
				if(t > pos[j].first){
					tf = false;
					break;
				}
				t = pos[j].second;
				i2 = pos[j].second;
			}
			t = 0;
			for(int j=i+1; j<10; j++){
				if(pos[j].first==INF)	continue;
				i1 = min(i1, pos[j].first);
				if(t > pos[j].first){
					tf = false;
					break;
				}
				t = pos[j].second;
			}
			if(i1==INF){
				i2 = N+1;
			}else if(i2==-1){
				i2 = 0;
			}else{
				set<int>::iterator it = st[i].lower_bound(i1);
				if(it!=st[i].end() && (*it)<=i2){
					tf = false;
				}
			}
			if(tf){
				//cout<<i<<" "<<i2<<endl;
				for(int j=0; j<N; j++){
					if(str[j]=='0'+i){
						if(j>=i2){
							str[j]='1';
						}else{
							str[j] = '2';
						}
					}else if(str[j]<('0' + i)){
						str[j] = '1';
					}else{
						str[j] = '2';
					}
				}
				cout<<str<<endl;
				break;
			}
		}
		if(!tf){
			printf("-\n");
		}
	}
	return 0;
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int LAR = 100050;

typedef long long ll;
typedef pair<ll, ll> P;

int m,n;
vector<int> seq;
vector<int> num;
vector<ll> numpos;
vector<P> pa;
vector<ll> papos;
ll cur = 0;

int get_num(ll index){
	//if(index < LAR) return seq[index];
	
	int upp = upper_bound(numpos.begin(), numpos.end(), index) - numpos.begin();
	int low = lower_bound(numpos.begin(), numpos.end(), index) - numpos.begin();
	//cout << "upp = " << upp << " low = " << low << endl;
	if(upp - low == 1){
		return num[low];
	}
	
	int pos = upper_bound(papos.begin(), papos.end(), index) - papos.begin() - 1;
	ll mod = pa[pos].first;
	return get_num((index - papos[pos]) % mod);
}

int main(){
	cin >> m;
	for(int t = 0; t < m; t++){
		int k,a,b;
		scanf("%d", &k);
		if(k == 1){
			scanf("%d", &a);
			//if(seq.size() < LAR) seq.push_back(a);
			num.push_back(a);
			numpos.push_back(cur);
			cur++;
		}
		else{
			scanf("%d%d", &a, &b);
//			if(seq.size() < LAR ){
//				for(int i = 0; i < b; i++){
//					if(seq.size() > LAR) break;
//					for(int j = 0; j < a; j++){
//						seq.push_back(seq[j]);
//					}
//				}
//			}
			pa.push_back(P(a,b));
			papos.push_back(cur);
			cur += (ll)a * b;
		}
	}
	cin >> n;
	ll ind;
	for(int i = 0; i < n; i++){
		cin >> ind;
		ind --;
		cout << get_num(ind) << " ";
	}
	
}
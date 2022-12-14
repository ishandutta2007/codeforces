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
const int MAX_N = 1000;

int T, N;
int arr[MAX_N+1];

int cnt[MAX_N+1];
priority_queue<int, vector<int>, greater<int> > pq1, pq2;

int getm(){
	while(!pq1.empty() && !pq2.empty()){
		if(pq1.top()==pq2.top()){
			pq1.pop(); pq2.pop();
		}else{
			break;
		}
	}
	return pq1.top();
}
vector<int> ans;

vector<int> idx[MAX_N+1];

void chg(int x, int y){
	cnt[arr[x]]--;
	if(cnt[arr[x]]==0){
		pq1.push(arr[x]);
	}
	arr[x] = y;
	idx[y].pb(x);
	ans.pb(x);
	cnt[arr[x]]++;
	if(cnt[arr[x]]==1){
		pq2.push(arr[x]);
	}

}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		while(!ans.empty())	ans.pop_back();
		for(int i=0; i<=N; i++){
			while(!idx[i].empty())	idx[i].pop_back();
			cnt[i] = 0;
		}
		for(int i=0; i<N; i++){
			scanf("%d", &arr[i]);
			cnt[arr[i]]++;
			idx[arr[i]].pb(i);
		}
		while(!pq1.empty())	pq1.pop();
		while(!pq2.empty())	pq2.pop();
		for(int i=0; i<=N; i++){
			if(cnt[i]==0)	pq1.push(i);
		}

		for(int i=0; i<N; i++){
			for(int j : idx[i]){
				//cout<<i<<" "<<j<<endl;
				if(j==i)	continue;
				if(arr[j]!=i)	continue;
				int m;
				while(1){
					m = getm();
					if(m==N)	break;
					if(m==i)	break;
					chg(m, m);
				}
				if(arr[j]!=i)	continue;
				chg(j, m);
			}
			if(arr[i]==i)	continue;
			//TEST cout<<i<<" "<<arr[i]<<" "<<getm()<<endl;
			int m = getm();
			chg(i, m);
			//TEST cout<<arr[i]<<endl;
		}
		/*
		for(int i=0; i<N; i++){
			printf("%d ", arr[i]);
		}printf("\n");
		//*/
		printf("%d\n", (int)ans.size());
		for(int i : ans){
			printf("%d ", i+1);
		}printf("\n");
	}
	return 0;
}
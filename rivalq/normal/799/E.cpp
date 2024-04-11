// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


struct sum_queue{
	priority_queue<int> pq;
	multiset<int> ms;
	int val = 0;
	int cnt = 0;

	void add(int x){
		if(cnt == 0){
			ms.insert(x);
			return;
		}
		if(pq.size() < cnt){
			pq.push(x);
			val += x;
		}else{
			auto u = pq.top();
			if(u > x){
				val -= u;
				val += x;
				pq.pop();
				ms.insert(u);
				pq.push(x);
			}else{
				ms.insert(x);
			}
		}
	}
	int get(int c){
		if(sz(pq) + sz(ms) < c){
			return -1;
		}

		while(sz(pq) < c){
			auto u = *ms.begin();
			val += u;
			ms.erase(ms.find(u));
			pq.push(u);
		}
		cnt = c;
		return val;
	}
	int size(){
		return sz(pq) + sz(ms);
	}

}st;


int solve(){
 		int n,m,k; cin >> n >> m >> k;
 		if(k > m){
 			cout << -1 << endl;
 			return 0;
 		}
 		int ans = LLONG_MAX;
 		vector<int> cost(n);

 		for(auto &i : cost) cin >> i;

 		vector<int> fr(n);
 		
 		rep(j,0,2){
 			int k; cin >> k;
 			while(k--){
 				int x; cin >> x; 
 				x--;
 				fr[x] += (1 << j);
 			}
 		}	
 		vector<vector<int>> vec(4);

 		rep(j,0,4){
 			vec[j].push_back(0);
 		}

 		for(int i = 0; i < n; i++){
 			vec[fr[i]].push_back(cost[i]);
 		}
 		for(auto &costs:vec){
 			sort(all(costs));
 			
 		}	
 		vector<int> pre = vec[3];
 		for(int i = 1; i < vec[3].size(); i++)pre[i] += pre[i - 1];

 		int ptr1 = min(k,sz(vec[1]) - 1);
 		int ptr2 = min(k,sz(vec[2]) - 1);
 		int cost_1 = 0;
 		int cost_2 = 0;
 		int cost_3 = 0;

 		for(int i = 1; i <= ptr1; i++)cost_1 += vec[1][i];
 		for(int i = 1; i <= ptr2; i++)cost_2 += vec[2][i];

 		for(int j = 1; j < vec[0].size(); j++){
 			st.add(vec[0][j]);
 		}
 		for(int i = ptr1 + 1; i < vec[1].size(); i++){
 			st.add(vec[1][i]);
 		}
 		for(int i = ptr2 + 1; i < vec[2].size(); i++){
 			st.add(vec[2][i]);
 		}
 		for(int i = k + 1; i < vec[3].size(); i++){
 			st.add(vec[3][i]);
 		}

 		int reqd = m - 2*k;
 		auto calc_answer = [&](int taken){
 			int rem = k - taken;
 			if(ptr1 == rem and ptr2 == rem){
 				if(reqd >= 0){
 					if(st.size() < reqd){
 						int more = reqd - st.size();
	 					if(taken + more <= k){
	 						int extra = pre[taken + more] - pre[taken];
	 						mins(ans,cost_1 + cost_2 + extra + cost_3 + st.get(st.size()));
	 					}	
 					}else{
 						mins(ans,cost_1 + cost_2 + cost_3 + st.get(reqd));
 					}
 				}
 			}
 		};

 		calc_answer(0);

 		for(int taken = 1; taken <= k; taken++){
 			if(taken >= vec[3].size() or taken > m){
 				break;
 			}
 			cost_3 += vec[3][taken];
 			int rem = k - taken;
 			reqd++;
 			while(ptr1 > rem and ptr1 > 0){
 				st.add(vec[1][ptr1]);
 				cost_1 -= vec[1][ptr1--];
 			}	
 			while(ptr2 > rem and ptr2 > 0){
 				st.add(vec[2][ptr2]);
 				cost_2 -= vec[2][ptr2--];
 			}
 			calc_answer(taken); 		
 		}

 		if(ans == LLONG_MAX){
 			ans = -1;
 		}
 		cout << ans << endl;





 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
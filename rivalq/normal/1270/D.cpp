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


int solve(){
 		int n,k; cin >> n >> k;

 		auto ask = [&](vector<int> v){
 			cout << "? ";
 			for(auto i:v)cout << i << " ";
 			cout << endl << flush;
 			int x; cin >> x;
 			int val; cin >> val;
 			return pii{x,val};
 		};
 		if(k == 1){
 			cout << "! " << 1 << endl;
 			return 0;
 		}
 		vector<int> temp;
 		for(int i = 1; i <= k; i++)temp.push_back(i);
 		auto p = ask(temp);
 		temp.clear();
 		temp.push_back(k + 1);
 		temp.push_back(p.x);
 		int cnt_left = 0,cnt_right = 0;
 		int remain_same = 0;
 		vector<pii> vec;
 		for(int i = 1; i <= k; i++){
 			if(i == p.x)continue;
 			auto t = temp;
 			for(int j = 1; j <= k; j++){
 				if(j == i or j == p.x)continue;
 				t.push_back(j);
 			}
 			auto p2 = ask(t);
 			if(p.y < p2.y){
 				cnt_left++;
 			}else if(p.y > p2.y){
 				cnt_right++;
 			}else{
 				remain_same++;
 			}
 			vec.push_back(p2);
 		}
 		assert(cnt_left == 0 or cnt_right == 0);
 		if(cnt_left > 0){
 			cout << "! " <<  cnt_left + 1 << endl << flush;
 		}else if(cnt_right > 0){
 			cout << "! " <<  k - cnt_right << endl << flush;
 		}else{
 			temp.clear();
 			for(int i = 1; i <= k + 1; i++){
 				if(i != p.x)temp.push_back(i);
 			}
 			auto res = ask(temp);
 			if(res.y < p.y){
 				cout <<"! "<<  k << endl << flush;
 			}else{
 				cout <<"! "<<  1 << endl << flush;
 			}
 		}



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
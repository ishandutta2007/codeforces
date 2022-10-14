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

const int I = 2e18;

int mod_inv(int a,int m) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
}

int solve(){
		int x; cin >> x;
		vector<array<string,3>>vec;

		auto add = [&](int x,string op,int y){
			vec.push_back({to_string(x),op,to_string(y)});
		};

		vector<int>num;
		num.push_back(x);
		add(x,"^",x);
		while(num.back() <= I){
			add(num.back(),"+",num.back());
			num.push_back(2*num.back());
		}

		auto create = [&](int a,int x){
			int p = 0;
			for(int j = 60; j >= 0; j--){
				if((1LL << j)&a){
					int val = 1LL << j;
					val *= x;
					add(p,"+",val);
					p += val;
				}
			}
			assert(p == a*x);
		};

		int val = 1;

		while(2*val <= x)val*=2;
		create(val,x);
		int y = x^(x*val);
		add(x,"^",x*val);

		vector<int>t;
		t.push_back(y);
		while(t.back() <= I){
			add(t.back(),"+",t.back());
			t.push_back(2*t.back());
		}
		// we have x = x, y = ((2**n)x)^x
		// we need a,b st ax - by = 1;
		int a = mod_inv(x,y);
		int b = (a*x - 1)/y;
		if(b%2 == 0){
			create(a,x);
			create(b,y);
			add(a*x,"^",b*y);
		}
		else{
			a += y;
			b += x;
			create(a,x);
			create(b,y);
			add(a*x,"^",b*y);
		}
		cout << vec.size() << endl;
		for(auto i:vec){
			cout << i[0] << " " << i[1] << " "<< i[2] << endl;
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
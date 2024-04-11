#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}



int expo(int x,int y,int p){
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}

struct ODT{
	int n;
	map<pii,int>st;  //range [L,R] with same value;
	// splits range [L,R] to [L,x) and [x,R]
	// returns iterator to [x,R]
	ODT(int n):n(n){
		st.insert({{1,n},0});
	}
	auto split(int x){
		if(x>n)return st.end();
		auto it=st.upper_bound({x,0});
		if(it==st.end())it--;
		if(it->x.x>x)it--;
		if(it->x.x==x)return it;
		int l=it->x.x;
		int r=it->x.y;
		int v=it->y;
		st.erase(it);
		st.insert({{l,x-1},v});
		return st.insert({{x,r},v}).x;
	}
	void assign(int l,int r,int val){
		auto itr=split(r+1);
		auto itl=split(l);
		st.erase(itl,itr);
		st.insert({{l,r},val});
	}
	void radd(int l,int r,int x){
		auto itr=split(r+1),itl=split(l);
		for(;itl!=itr;itl++){
			itl->y+=x;
		}
	}
	int kth(int l,int r,int k){
		vector<pii>vec;
		auto itr=split(r+1),itl=split(l);
		for(;itl!=itr;itl++){
			vec.pb({itl->y,itl->x.y-itl->x.x+1});
		}
		sort(vec.begin(),vec.end());
		for(auto i:vec){
			if(i.y>=k)return i.x;
			k-=i.y;
		}
		return 0;
	}
	int query(int l,int r,int x,int y){
		auto itr=split(r+1),itl=split(l);
		int ans=0;
		for(;itl!=itr;itl++){
			int val=expo(itl->y,x,y);
			val=val*(itl->x.y-itl->x.x+1);
			ans=(ans+val)%y;
		}
		if(ans<0)ans+=y;
		return ans;
	}

};

int n,m,seed,vmax;

int rnd(){

    int ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;

}
int solve(){
 	
 	cin>>n>>m>>seed>>vmax;
 	vector<int>a(n+1);
 	rep(i,1,n+1){
 		a[i]=rnd()%vmax+1;
 	}
 	ODT odt=ODT(n);
 	int i=1;
 	while(i<=n){
 		int j=i;
 		while(j<=n && a[i]==a[j])j++;
 		odt.assign(i,j-1,a[i]);
 		i=j;
 	}
 	rep(i,0,m){
 		int op = (rnd() % 4) + 1;
    		int l =  (rnd() % n) + 1;
    		int r =  (rnd() % n) + 1;
    		int x=0,y=0;
		if (l > r)swap(l, r);
		if(op == 3){
			 x = (rnd() % (r - l + 1)) + 1;
		}
     		else{
     			 x = (rnd() % vmax) + 1;	
     		}
       		if (op == 4){
        		y = (rnd() % vmax) + 1;
       		}


       		if(op==1){
       			odt.radd(l,r,x);
       		}
       		else if(op==2){
       			odt.assign(l,r,x);
       		}
       		else if(op==3){
       			cout<<odt.kth(l,r,x)<<endl;
       		}
       		else{
       			cout<<odt.query(l,r,x,y)<<endl;
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
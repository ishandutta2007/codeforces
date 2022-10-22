#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace __gnu_pbds;
using namespace std;
const int mod = 0;
const int maxn = 300100;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
typedef long double ld;
template<typename T>using heap=__gnu_pbds::priority_queue<T>;
template<typename T>using rbt=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>inline istream&operator,(istream&cin,T&x){return cin>>x;}
template<typename T>inline ostream&operator,(ostream&cout,const T&x){return cout<<x;}
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline int pow(int a,int b,int ans=1){
	for(;b;b>>=1,a=ll(a)*a%mod)
		if(b&1)ans=ll(ans)*a%mod;
	return ans;
}
inline int inv(int a){return pow(a,mod-2);}
int n,m;
int bak[2];
int c[2],x;
int main(){
	in,n,m;
	rep(i,1,n){
		in,x;
		++bak[x&1];
	}
	rep(i,1,m){
		in,x;
		++c[x&1];
	}
	out,(min(c[1],bak[0])+min(c[0],bak[1]));
}
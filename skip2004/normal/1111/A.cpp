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
using namespace __gnu_pbds;
using namespace std;
const int mod = 0;
const int maxn = 100100;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
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
inline int chk(int x){
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	std::string a,b;
	in,a,b;
	if(a.size()!=b.size()){
		out,"No";
		return 0;
	}
	for(int i=0;i<a.size();++i){
		if(a[i]==b[i] || chk(a[i])==chk(b[i])){
		}else{
		out,"No";
		return 0;
		}
	}
	out,"Yes";
}
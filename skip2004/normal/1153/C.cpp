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
const int mod = 1e9 + 7;
const int maxn = 1001000;
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
inline int pow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=ll(a)*a%mod)
		if(b&1)ans=ll(ans)*a%mod;
	return ans;
}
inline int inv(int a){return pow(a,mod-2);}
int r[maxn];
int main(){
	int n;string str,ans;
	in,n,str;int tp=0;
	for(int i=n-1;i>=0;--i) r[i]=r[i+1]+(str[i]!='(')-(str[i]=='(');
	for(int i=0;i<n;++i){
		if(str[i]!='?'){
			ans+=str[i];
			if(str[i]=='(')++tp;
			else --tp;
		}else{
			if(tp+1<=r[i+1])
				++tp,ans+='(';
			else --tp,ans+=')';
		}
		if(tp<0){
			puts(":(");
			return 0;
		}
		if(tp==0&&i!=n-1){
			puts(":(");
			return 0;
		}
	}
		if(tp!=0){
			puts(":(");
			return 0;
		}
	out,ans;
}
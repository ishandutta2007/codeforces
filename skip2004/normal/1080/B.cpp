#include<bits/stdc++.h>
using namespace std;
template <typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template <typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
namespace io{
	struct input{
		inline input(){ios::sync_with_stdio(false),cin.tie(0);}	
		template <typename _>inline input& operator , (_&x){cin>>x;return*this;}
		template <typename _>inline input& operator >>(_&x){cin>>x;return*this;}
	};
	struct output{
		template <typename _>inline output& operator, (const _&x){cout<<x;return*this;}
		template <typename _>inline output& operator>>(const _&x){cout<<x;return*this;}
	};
}
io::input in;
io::output out;
inline int sg(int a){
	return a%2?-1:1;
}
inline long long c(int r){
	int j = r/2*2;
	return j/2 + (j!=r?r*sg(r):0);
}
int main(){
	int q;
	in,q;
	while(q--){
		int l,r;
		in,l,r;
		out,c(r)-c(l-1),'\n';
	}
}
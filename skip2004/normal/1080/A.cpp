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
int n,k;
inline int c(int n,int k,int p){
	n*=p;
	return (n+k-1)/k;
}
int main(){
	in,n,k;
	out,c(n,k,2)+c(n,k,5)+c(n,k,8);
}
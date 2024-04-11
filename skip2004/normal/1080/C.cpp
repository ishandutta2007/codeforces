#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template <typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
namespace io{
	struct input{
		inline input(){/*ios::sync_with_stdio(false),cin.tie(0);*/}	
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
#define int long long
int t;
inline int calcb(int x,int y){
	return x*y/2;
}
inline int calcw(int x,int y){
	return x*y-calcb(x,y);
}
inline int calcb(int x1,int y1,int x2,int y2){
	if(x1>x2)return 0;
	if(y1>y2)return 0;
	return calcb(x2,y2)-calcb(x2,y1-1)-calcb(x1-1,y2)+calcb(x1-1,y1-1);
}
inline int calcw(int x1,int y1,int x2,int y2){
	if(x1>x2)return 0;
	if(y1>y2)return 0;
	return calcw(x2,y2)-calcw(x2,y1-1)-calcw(x1-1,y2)+calcw(x1-1,y1-1);
}
inline int S(int x1,int y1,int x2,int y2){
	return(x2-x1+1)*(y2-y1+1);
}
inline int calc(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	if(x1>x3)return calc(x3,y3,x4,y4,x1,y1,x2,y2);
	return calcb(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
}
main(){
	in,t;
	while(t--){
		ll n,m;
		in,m,n;
		ll w=calcw(n,m),b=calcb(n,m);
		ll x1,x2,x3,x4,y1,y2,y3,y4;
		in,x1,y1,x2,y2;
		in,x3,y3,x4,y4;
		
		b-=calcb(x1,y1,x2,y2);
		w+=calcb(x1,y1,x2,y2);
		
		b+=calcw(x3,y3,x4,y4);
		w-=calcw(x3,y3,x4,y4);
		
		w-=calc(x1,y1,x2,y2,x3,y3,x4,y4);
		b+=calc(x1,y1,x2,y2,x3,y3,x4,y4);
		out,w,' ',b,'\n';
	}
}
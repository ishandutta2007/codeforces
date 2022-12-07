#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint num[110000];
map<lint,int> me;
string moji(lint a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string dec(lint t){
	string ret="";
	ret+=moji(t/(1<<24));ret+=".";
	ret+=moji((t/(1<<16))%256);ret+=".";
	ret+=moji((t/256)%256);ret+=".";
	ret+=moji(t%256);return ret;
}
int main()
{
	int n,k;lint a,b,c,d;char x,y,z;
	cin>>n>>k;
	rep(i,n){
		cin>>a>>x>>b>>y>>c>>z>>d;
		num[i]=(a<<24)+(b<<16)+(c<<8)+d;
		//cout<<num[i]<<endl;
	}
	rep(i,32){
		lint t=((1LL<<32)-(1LL<<(31-i)));
		me.clear();
		//cout<<(t&num[i])<<endl;
		rep(j,n){
			//cout<<(t&num[j])<<endl;
			if(!me[(t&num[j])]) me[(t&num[j])]++;
		}
		//cout<<me.size()<<endl;
		if(me.size()==k){
			cout<<dec(t)<<endl;return 0;
		}
	}
	cout<<-1<<endl;return 0;
}
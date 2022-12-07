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
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long Int;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
string moji(Int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
int abso(int a){
	if(a<0) return -a;return a;
}
string calc(Int a,Int b,Int c){
	if(a==0){
		if(c%b!=0) return "-1";
		else return "0 "+moji((-c)/b);
	}
	if(b==0){
		if(c%a!=0) return "-1";
		else return moji((-c)/a)+" 0";
	}
	if(c==0) return moji(b)+" "+moji(-a);
	if(a<0){a=-a;b=-b;c=-c;}
	int s=gcd(a,abso(b));
	if(c%s!=0) return "-1";
	a/=s;b/=s;c/=s;
	if(b>0){
		Int s=invMod(a,b),t=-((s*c)%b),u=(-c-(t*a))/b;
		return moji(t)+" "+moji(u);
	}
	else{
		Int s=invMod(a,-b),t=-((s*c)%(-b)),u=(-c-(t*a))/b;
		return moji(t)+" "+moji(u);
	}
}
int main()
{
	Int a,b,c;cin>>a>>b>>c;
	string ka=calc(a,b,c);
	cout<<ka<<endl;
	return 0;
}
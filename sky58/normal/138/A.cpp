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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
string bo="aeiou";
string da[4]={"A","B","C","D"};
string ch[4]={"aaaa","aabb","abba","abab"};
bool isbo(char a){
	int i;
	rep(i,5){
		if(a==bo[i]) return true;
	}
	return false;
}
int main()
{
	int i,j,k,m,n,l;vector < vector <string> > out;string s;
	cin>>n>>m;
	rep(i,n){
		vector <string> a;
		rep(j,4){
			cin>>s;int t=0;
			for(k=s.size()-1;k>=0;k--){
				if(isbo(s[k])) t++;
				if(t==m){
					a.pb(s.substr(k));break;
				}
			}
			if(a.size()<=j) a.pb(da[j]);
		}
		out.pb(a);
	}
	rep(i,4){
		int f=0;
		rep(j,3) REP(k,j+1,4){
			if(ch[i][j]!=ch[i][k]) continue;
			rep(l,n){
				if(out[l][j]!=out[l][k]) f=1;
			}
		}
		if(f<1){
			cout<<ch[i]<<endl;return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
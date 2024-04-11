#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
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
int num[26];
bool used[114514];
int le[114514],ri[114514];
int n,m;
string s,out="";
vector<int> v;
bool ok(void){
	int now=-1;
	rep(i,n){
		if(used[i]) now=i;
		//cout<<i<<' '<<now<<endl;
		if(i-now>=m) return false;
	}
	return true;
}
int main()
{
	cin>>m;cin>>s;n=s.size();
	memset(used,false,sizeof(used));
	rep(i,26){
		rep(j,n){
			if(i==(s[j]-'a')) used[j]=true;
		}
		if(ok()){
			int now=-1;
			rep(j,n){
				if(!used[j]) continue;
				le[j]=now;now=j;
			}
			now=n;
			for(int j=n-1;j>=0;j--){
				if(!used[j]) continue;
				ri[j]=now;now=j;
			}
			rep(j,n){
				if(i!=(s[j]-'a')) continue;
				if(ri[j]-le[j]<=m){
					used[j]=false;
					int r=ri[j],l=le[j];
					ri[l]=r;le[r]=l;
				}
			}
			//cout<<i<<endl;
			break;
		}
	}
	rep(i,n){
		if(used[i]) out+=s[i];
	}
	sort(All(out));
	cout<<out<<endl;
}
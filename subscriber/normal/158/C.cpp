#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,t;
string o,s,e;
vector<string>a,b;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> o;
		if (o=="pwd"){
			for (int j=0;j<a.size();j++)cout << '/' << a[j];
			puts("/");
		}else{
			cin >> s;
			if (s[0]=='/'){
				t=1;
				s.erase(s.begin());
			}else t=0;
			if (s.size())s+='/';
			b.clear();
			for (int j=0;j<s.size();j++)if (s[j]=='/'){
				b.pb(e);
				e="";
			}else e+=s[j];
			if (t)a=b;else for (int j=0;j<b.size();j++)a.pb(b[j]);
			b.clear();
			for (int j=0;j<a.size();j++)if (a[j]=="..")b.erase(b.end()-1);else b.pb(a[j]);
			a=b;
		}
	}
	return 0;
}
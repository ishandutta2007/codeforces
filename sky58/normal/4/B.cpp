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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int n,s;
vector <int> c,d;
bool ch(int t,int ke){
	int i,mi=0,ma=0;
	for(i=t;i<n;i++){mi+=c[i];ma+=d[i];}
	if(mi>s-ke || ma<s-ke) return false;return true;
}
vector <int> cal(void){
	vector <int> ret,r;
	int i,j,ke=0;
	for(i=0;i<n;i++){
		int f=0;
		for(j=d[i];j>=c[i];j--){
			if(ch(i+1,ke+j)){ret.pb(j);f++;ke+=j;break;}
		}
		if(f==0) return r;
	}
	return ret;
}
int main()
{
	cin>>n>>s;int i;
	for(i=0;i<n;i++){
		int a,b;cin>>a>>b;c.pb(a);d.pb(b);
	}
	vector <int> out=cal();
	if(out.size()==0) cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(i=0;i<out.size()-1;i++) cout<<out[i]<<' ';
		cout<<out[out.size()-1]<<'\n';
	}
	return 0;
}
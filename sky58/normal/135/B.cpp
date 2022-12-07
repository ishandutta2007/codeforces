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
int x[10],y[10];
bool sq(string a){
	int dx[4],dy[4];int i;
	a+=a[0];
	rep(i,4){
		dx[i]=x[(a[i+1]-'0')]-x[(a[i]-'0')];
		dy[i]=y[(a[i+1]-'0')]-y[(a[i]-'0')];
	}
	rep(i,3){
//		cout<<dx[i]<<' '<<dy[i]<<' '<<dx[i+1]<<' '<<dy[i+1]<<endl;
		if(dx[i]!=dy[i+1] || dx[i+1]!=(-dy[i])) return false;
	}
	return true;
}
bool re(string a){
	int dx[4],dy[4];int i;
	a+=a[0];
	rep(i,4){
		dx[i]=x[(a[i+1]-'0')]-x[(a[i]-'0')];
		dy[i]=y[(a[i+1]-'0')]-y[(a[i]-'0')];
	}
	rep(i,3){
//		cout<<dx[i]<<' '<<dy[i]<<' '<<dx[i+1]<<' '<<dy[i+1]<<endl;
		if(dx[i]*dx[i+1]!=((-dy[i+1])*dy[i])) return false;
	}
	return true;
}
int main()
{
	string a="01234567";int i;
	rep(i,8) cin>>x[i]>>y[i];
	while(1){
		string b=a.substr(0,4),c=a.substr(4,4);
		if(sq(b) && re(c)){
//			cout<<b<<' '<<c<<endl;
			sort(All(b));sort(All(c));
			cout<<"YES"<<endl;
			rep(i,4){
				cout<<((b[i]-'0')+1);if(i<3) cout<<" ";
			}
			cout<<endl;
			rep(i,4){
				cout<<((c[i]-'0')+1);if(i<3) cout<<" ";
			}
			cout<<endl;
			return 0;
		}
		if(!next_permutation(All(a))) break;
	}
//	if(re("0213")) cout<<"a"<<endl;;
	cout<<"NO"<<endl;return 0;
}
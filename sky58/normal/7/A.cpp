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
int main()
{
	vector <string> s;int i,j,k,ret1=0,ret2=0;
	for(i=0;i<8;i++){
		string a;cin>>a;s.pb(a);
	}
/*	for(i=0;i<(1<<8);i++){
		int t=0;
		for(j=0;j<8;j++){
			int f=0;
			for(k=0;k<8;k++){
				if(!(i&(1<<k)) && s[j][k]=='B') f=1;
			}
			t+=f;
		}
//		cout<<i<<' '<<t<<endl;
		ret=min(ret,t+__builtin_popcount(i));
	}
*/
	for(i=0;i<8;i++){
		int f=1;
		for(j=0;j<8;j++){if(s[i][j]=='W') f=0;}
		ret1+=f;
	}
	for(i=0;i<8;i++){
		int f=1;
		for(j=0;j<8;j++){if(s[j][i]=='W') f=0;}
		ret2+=f;
	}
	if(ret1==8 && ret2==8) cout<<"8\n";
	else cout<<ret1+ret2<<endl;
	return 0;
}
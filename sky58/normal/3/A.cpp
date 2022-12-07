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
	string a,b;vector <string> out;cin>>a;cin>>b;
	int sx=(a[0]-'a'),sy=(a[1]-'0'),gx=(b[0]-'a'),gy=(b[1]-'0'),ret=max(abs(sx-gx),abs(sy-gy)),i;
	for(i=0;i<ret;i++){
		string s;
		if(sx>gx){s+='L';sx--;}
		if(sx<gx){s+='R';sx++;}
		if(sy>gy){s+='D';sy--;}
		if(sy<gy){s+='U';sy++;}
		out.pb(s);
	}
	cout<<ret<<endl;
	for(i=0;i<ret;i++) cout<<out[i]<<endl;
	return 0;
}
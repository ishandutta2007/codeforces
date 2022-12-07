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
#include<fstream>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
string cal(lint x,lint y,lint k){
	if(k==1){
		if(x%2>0 && y%2>0) return "-";return "+";
	}
	if(x%(k+1)==0) return "+";
	lint s=x/(k+1);if((x+y+s)%2>0) return "+";return "-";
}
int main()
{
	int i,t,k,x,y;vector <string> ret;
	ifstream ifs("input.txt");ofstream ofs("output.txt");
	ifs>>t>>k;
	for(i=0;i<t;i++){
		ifs>>x>>y;ret.pb(cal(min(x,y),max(x,y),k));
	}
	for(i=0;i<t;i++) ofs<<ret[i]<<endl;
	return 0;
}
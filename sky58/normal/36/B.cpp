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
vector <string> a,b;int n;
vector <string> rec(vector <string> in){
	vector <string> ret;string cl="";int m=in.size(),i,j;
	for(i=0;i<m*n;i++) cl+='.';for(i=0;i<m*n;i++) ret.pb(cl);
	for(i=0;i<m*n;i++) for(j=0;j<m*n;j++){
		if(in[i/n][j/n]=='*') ret[i][j]='*';
		else if(a[i%n][j%n]=='*') ret[i][j]='*';
	}
	return ret;
}
int main()
{
	ifstream ifs("input.txt");ofstream ofs("output.txt");
	string s;int i,j,k;ifs>>n>>k;
	for(i=0;i<n;i++){
		ifs>>s;a.pb(s);
	}
	b.pb(".");
//	cout<<n<<k<<endl;
	for(i=0;i<k;i++) b=rec(b);
//	cout<<n<<k<<endl;
	for(i=0;i<b.size();i++) ofs<<b[i]<<endl;
	return 0;
}
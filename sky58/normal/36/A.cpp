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
int main()
{
	int n,i;vector <int> a;
	ifstream ifs("input.txt");ofstream ofs("output.txt");
	string s;
//	getline(ifs,s);
//	istringstream sin(s);sin>>n;
//	getline(ifs,s);
	ifs>>n;ifs>>s;
//	cout<<n<<s<<endl;
	for(i=0;i<n;i++){
		if(s[i]=='1') a.pb(i);
	}
	for(i=0;i<a.size()-2;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){ofs<<"NO"<<endl;return 0;}
	}
	ofs<<"YES"<<endl;return 0;
}
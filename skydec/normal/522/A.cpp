#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
int n;
multimap<string,string> edge;
map<string,int> maxd;
int tryy(string s)
{
	if(maxd[s])
		return maxd[s];
	auto l=edge.lower_bound(s),r=edge.upper_bound(s);
	for(auto it=l;it!=r;++it)
		maxd[s]=max(maxd[s],tryy(it->second));
	return ++maxd[s];
}
int main()
{	
	cin>>n;
	string s1,s2,tmp;
	for(int i=1;i<=n;++i)
	{
		cin>>s1>>tmp>>s2;
		for(int j=0;j<(int)s1.size();++j)
			s1[j]=tolower(s1[j]);
		for(int j=0;j<(int)s2.size();++j)
			s2[j]=tolower(s2[j]);
		edge.insert({s2,s1});
	}
	cout<<tryy("polycarp")<<endl;
	return 0;
}
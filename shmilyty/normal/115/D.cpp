#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
long long f[1005][2005],g[2005];
vector<int> v;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int cur=0,cnt=0;
	rep(i,s.length())
	{
		if(s[i]<'0'||s[i]>'9')
			cur++;
		else
			if(cur)
			{
				v.push_back(cur);
				cur=0;
			}
		if((i==0||s[i-1]<'0'||s[i-1]>'9')&&(s[i]=='*'||s[i]=='/'))
		{
			cout<<0<<endl;
			return 0;
		}
	}
	if(cur)
	{
		cout<<0<<endl;
		return 0;
	}
	f[0][0]=1LL;
	rep(i,v.size())
	{
		int c=v[i];
		g[0]=f[i][0];
		for(int l=1;l<=cnt;l++)
			g[l]=(g[l-1]+f[i][l])%1000003LL;
		for(int l=cnt+c;l>=0;l--)
		{
			f[i+1][l]=g[cnt];
			if(max(l-c,0)!=0)
				f[i+1][l]+=1000003LL-g[max(l-c,0)-1];
			f[i+1][l]%=1000003LL;
		}
		cnt+=c;
	}
	cout<<f[v.size()][0]<<endl;
	return 0;
}
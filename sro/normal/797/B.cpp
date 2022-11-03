#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define FILL(a,v) memset(a,v,sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define INT long long
#define UINT unsigned long long
#define Uint unsigned int
#define PII pair<INT,INT>
#define SZ(a) ((int)(a).size())
#define _X first
#define _Y second
using namespace std;
using namespace __gnu_cxx;

vector<int> zdj,fdj;
int zsh=0;

int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>0)zsh+=a;
		if(a>0&&a%2) zdj.push_back(a);
		if(a<0&&(-a)%2) fdj.push_back(a);
	}
	if(zsh%2)return printf("%d\n",zsh),0;
	sort(zdj.begin(),zdj.end());
	sort(fdj.rbegin(),fdj.rend());
	if(zdj.size()==0) zdj.push_back(Inf);
	if(fdj.size()==0) fdj.push_back(-Inf);
	printf("%d\n",max(zsh-zdj[0],zsh+fdj[0]));
	return 0;
}
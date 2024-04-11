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
	int out=10000,t=0,i,j,n;string s;cin>>n;cin>>s;
	for(i=0;i<n;i++){if(s[i]=='T') t++;}
	for(i=0;i<n;i++){
		int f=0;
		for(j=0;j<t;j++){if(s[(i+j)%n]=='H') f++;}
		out=min(out,f);
	}
	cout<<out<<endl;
	return 0;
}
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
	int i,j,k,n,out=0;string s;
	cin>>s;n=s.size();
	for(i=0;i<n;i++) for(j=1;i+j<=n;j++){
		string c=s.substr(i,j);
		for(k=0;k+j<=n;k++){
			if(c==s.substr(k,j) && i!=k) out=max(out,j);
		}
	}
	cout<<out<<endl;
	return 0;
}
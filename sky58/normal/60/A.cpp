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
	int n,ma,mi=0,m,x,i;string a,b,c,d;
	cin>>n>>m;ma=n+1;
	for(i=0;i<m;i++){
		cin>>a>>b>>c>>d>>x;
		if(c=="left") ma=min(ma,x);else mi=max(mi,x);
	}
	if(ma<=mi+1) cout<<"-1"<<endl;
	else printf("%d\n",ma-mi-1);
	return 0;
}
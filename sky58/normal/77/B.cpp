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
	int i,n,a,b;double ret;cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;//cout<<a<<' '<<b<<endl;
		if(b==0){
			ret=1.0;
		}
		else if(a==0){
			ret=0.0;
		}
		else if(a<4*b){
			ret=0.125*a/b;
		}
		else{
			ret=1.0-2.0*b/a;
		}
		printf("%.9f\n",0.5+0.5*ret);
	}
	return 0;
}
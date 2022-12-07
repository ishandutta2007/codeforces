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
	int i;lint n,x,y;cin>>n>>x>>y;
	if(n>y){
		cout<<"-1"<<endl;return 0;
	}
	if(n-1+(y-n+1)*(y-n+1)<x){
		cout<<"-1"<<endl;return 0;
	}
	for(i=0;i<n-1;i++){
		cout<<"1"<<endl;
	}
	cout<<y-n+1<<endl;
	return 0;
}
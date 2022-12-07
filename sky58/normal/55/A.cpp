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
bool sumi[1100];
int main()
{
	int t=1,n;lint i=0;
	memset(sumi,false,sizeof(sumi));cin>>n;
	for(i=0;i<1000000;i++) sumi[(int)(((lint)i*(i+1)/2)%n)]=true;
	for(i=0;i<n;i++){
		if(!sumi[(int)i]) t=0;
	}
	if(t==1) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	return 0;
}
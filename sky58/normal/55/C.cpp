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
	int i,x,y,m,n,k;string out="NO";
	cin>>n>>m>>k;
	for(i=0;i<k;i++){
		cin>>x>>y;
		if(x<=5 || y<=5 || x>n-5 || y>m-5) out="YES";
	}
	cout<<out<<endl;
	return 0;
}
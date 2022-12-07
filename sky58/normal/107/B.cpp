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
int s[1100];
int main()
{
	int i,n,m,h,sum=0;double out=1.0;
	cin>>n>>m>>h;
	for(i=0;i<m;i++){
		scanf("%d",&s[i+1]);sum+=s[i+1];
	}
	if(sum<n){
		cout<<"-1.0"<<endl;return 0;
	}
	if(sum-s[h]+1<n){
		cout<<"1.0"<<endl;return 0;
	}
	for(i=0;i<n-1;i++){
		out*=(0.0+sum-s[h]-i);out/=(0.0+sum-i-1);
	}
	printf("%.12f\n",1.0-out);
	return 0;
}
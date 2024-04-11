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
lint ka[110000],ki[110000];int n;
lint cal(void){
//	if(ki[n-1]%3!=0) return 0;
	lint t=0,ret=0;
	for(int i=0;i<n-1;i++){
		if(ki[i]*3==ki[n-1]*2) ret+=t;
		if(ki[i]*3==ki[n-1]) t++;
//		if(ki[i]*3==ki[n-1]*2) ret+=t;
	}
	return ret;
}
int main()
{
	lint i,a,s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;s+=a;ka[i]=a;ki[i]=s;
	}
	cout<<cal()<<endl;
	return 0;
}
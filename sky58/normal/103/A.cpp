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
lint a[150];
int main()
{
	int i,n;lint out=0,t=1;cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
//	a[n]=1;
	for(i=n-1;i>=0;i--){
		lint t2=a[i]+t-1;out+=t2;t=t2;//out+=a[i+1]-1+a[i];
	}
	cout<<out<<endl;
	return 0;
}
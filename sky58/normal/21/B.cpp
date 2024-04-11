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
int cal(int a1,int b1,int c1,int a2,int b2,int c2){
	if(a1==0 && b1==0){
		if(c1!=0) return 0;
		if(c1==0){
			if(a2==0 && b2==0 && c2!=0) return 0;return -1;
		}
	}
	if(a2==0 && b2==0){
		if(c2!=0) return 0;
		if(c2==0){
			if(a1==0 && b1==0 && c1!=0) return 0;return -1;
		}
	}
	if(a1*b2==a2*b1){
		if(a1*c2==a2*c1 && b1*c2==b2*c1) return -1;return 0;
	}
	return 1;
}
int main()
{
	int a1,b1,c1,a2,b2,c2;
	cin>>a1>>b1>>c1;
	cin>>a2>>b2>>c2;
	cout<<cal(a1,b1,c1,a2,b2,c2)<<endl;
	return 0;
}
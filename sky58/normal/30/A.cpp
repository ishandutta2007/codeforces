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
bool ch(int i,int n,int b){
	int t=1;int j;
	for(j=0;j<n;j++){
		t*=i;if(abs(t)>abs(b)) return false;
	}
	if(t==b) return true;return false;
}
int main()
{
	int i,a,b,n;
	cin>>a>>b>>n;
	if(a==0){
		if(b==0){cout<<"0"<<endl;return 0;}
		cout<<"No solution"<<endl;return 0;
	}
	if(n==0){
		if(a==b){cout<<"0"<<endl;return 0;}
		cout<<"No solution"<<endl;return 0;
	}
	if(b%a>0){cout<<"No solution"<<endl;return 0;}
	b/=a;
	if(n==1){cout<<b<<endl;return 0;}
	for(i=-50;i<=50;i++){
		if(ch(i,n,b)){cout<<i<<endl;return 0;}
	}
	cout<<"No solution"<<endl;return 0;
}
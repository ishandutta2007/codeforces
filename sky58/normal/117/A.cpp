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
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	int n,m,a,b,c,i,k;
	cin>>n>>m;k=2*(m-1);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(a==b) cout<<c<<endl;
		else{
			if(a<b){
				cout<<((c+k-(a-1)-1)/k)*k+(a-1)+b-a<<endl;
			}
			else{
				cout<<((c+k/2-(m-a)-1)/k)*k+k/2+(m-a)+a-b<<endl;
			}
		}
	}
	return 0;
}
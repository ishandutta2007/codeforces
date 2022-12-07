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
	int i,n;cin>>n;
	if(n%2>0){
//		cout<<"-1"<<endl;return 0;
		cout<<"c";
		for(i=0;i<n/2;i++){
			if(i%2<1) cout<<"xx";else cout<<"yy";
		}
		cout<<endl;
		cout<<"c";
		for(i=0;i<n/2;i++){
			if(i%2<1) cout<<"zz";else cout<<"ww";
		}
		cout<<endl;
		for(i=0;i<n/2;i++){
			if(i%2<1) cout<<"xx";else cout<<"yy";
		}
		cout<<"d"<<endl;
		for(i=0;i<n/2;i++){
			if(i%2<1) cout<<"zz";else cout<<"ww";
		}
		cout<<"d"<<endl;
		return 0;
	}
	for(i=0;i<n/2;i++){
		if(i%2<1) cout<<"aa";else cout<<"bb";
	}
	cout<<endl;
	cout<<"c";
	for(i=0;i<n/2-1;i++){
		if(i%2<1) cout<<"xx";else cout<<"yy";
	}
	cout<<"d"<<endl;
	cout<<"c";
	for(i=0;i<n/2-1;i++){
		if(i%2<1) cout<<"ww";else cout<<"zz";
	}
	cout<<"d"<<endl;
	for(i=0;i<n/2;i++){
		if(i%2<1) cout<<"aa";else cout<<"bb";
	}
	return 0;
}
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int a[310];
int main()
{
	int n,pos=0,pp=0,lest=0;
	cin>>n;
	rep(i,n){cin>>a[i];lest+=a[i];}
	string out="";
	while(lest>0){
		if(a[pos]>0 && pp==0){
			a[pos]--;out+='P';pp=1;lest--;
		}
		else{
			pp=0;
			if(pos<1){out+='R';pos++;}
			else if(pos>=n-1){out+='L';pos--;}
			else{
				int f=0;
				rep(i,pos){
					if(a[i]>0) f=1;
				}
				if(f>0){out+='L';pos--;}
				else{out+='R';pos++;}
			}
		}
	}
	cout<<out<<endl;
}
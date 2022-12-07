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
string na[7]={"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"};
bool like[10][10];
int de(string a){
	for(int i=0;i<7;i++){
		if(a==na[i]) return i;
	}
}
int main()
{
	vector <vector <int> > bu;vector <int> cl;bu.pb(cl);bu.pb(cl);bu.pb(cl);
	int i,j,k,l,n,x,y,z,out2=0,out1=1000000000;string a,b,c;
	cin>>n;memset(like,false,sizeof(like));
	for(i=0;i<n;i++){
		cin>>a>>b>>c;like[de(a)][de(c)]=true;
	}
	cin>>x>>y>>z;
	for(i=0;i<2403;i++){
		for(j=0;j<3;j++) bu[j]=cl;int f=0,t=i,li=0;vector <int> ma;
		for(j=0;j<7;j++){
			bu[t%3].pb(j);t/=3;
		}
		for(j=0;j<3;j++){
			if(bu[j].size()<1) f=1;
		}
		if(f>0) continue;
		ma.pb(x/bu[0].size());ma.pb(y/bu[1].size());ma.pb(z/bu[2].size());
		sort(ma.begin(),ma.end());
		for(j=0;j<3;j++){
			for(k=0;k<bu[j].size();k++) for(l=0;l<bu[j].size();l++){
				if(like[bu[j][k]][bu[j][l]]) li++;
			}
		}
		if(ma[2]-ma[0]<out1 || (ma[2]-ma[0]==out1 && li>out2)){out1=ma[2]-ma[0];out2=li;}
	}
	cout<<out1<<' '<<out2<<endl;
	return 0;
}
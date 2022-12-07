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
#define fi first.first
#define se first.second
#define th second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
bool sumi[1100];
int main()
{
	int i,j,n,ma,reg,hp,at=0,a,b;
	vector <int> out1,out2;vector <tint> spe;
	cin>>n>>ma>>reg;hp=ma;
	for(i=0;i<n;i++){
		cin>>a>>b;spe.pb(mp(mp(b,a),i));
	}
	sort(spe.begin(),spe.end());reverse(spe.begin(),spe.end());
	for(i=0;i<3000;i++){
		hp-=at;hp+=reg;hp=min(hp,ma);if(hp<=0){cout<<"YES"<<endl;cout<<i<<' '<<out1.size()<<endl;break;}
		int f=0;
		for(j=0;j<n && f<1;j++){
			if(!sumi[j] && spe[j].se*ma>=hp*100){
				sumi[j]=true;out1.pb(i);out2.pb(spe[j].th+1);at+=spe[j].fi;f=1;
			}
		}
	}
	if(hp>0){cout<<"NO"<<endl;return 0;}
	for(i=0;i<out1.size();i++) cout<<out1[i]<<' '<<out2[i]<<endl;return 0;
}
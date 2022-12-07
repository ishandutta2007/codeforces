#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,s,k1,k2,k3,a,a1,a2,a3,ans=1e9,e,x;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> s;
	for (int i=0;i<n;i++){
		cin >> a;
		if (a==3)k1++;else if (a==4)k2++;else k3++;
	}
	for (int i=0;i*k2<=s;i++){
		x=i*k2;
		e=s-x;
		int g2=min(e-i*k3,i*k1);
		int g1=0;
		if (e%__gcd(k1,k3))continue;
		if (x>g2){
			for (int j=g2;j>=g1;j--)if (j%k1==0&&(e-j)%k3==0){
				if (abs(i*k2-j)+abs(i*k2-(e-j))<ans)ans=abs(i*k2-j)+abs(i*k2-(e-j)),a1=j/k1,a2=i,a3=(e-j)/k3;
				break;
			}
		}else{
			for (int j=x;j<=g2;j++)if (j%k1==0&&(e-j)%k3==0){
				if (abs(i*k2-j)+abs(i*k2-(e-j))<ans)ans=abs(i*k2-j)+abs(i*k2-(e-j)),a1=j/k1,a2=i,a3=(e-j)/k3;
				break;
			}
			for (int j=x;j>=g1;j--)if (j%k1==0&&(e-j)%k3==0){
				if (abs(i*k2-j)+abs(i*k2-(e-j))<ans)ans=abs(i*k2-j)+abs(i*k2-(e-j)),a1=j/k1,a2=i,a3=(e-j)/k3;
				break;
			}
		}
	}
	if (ans>1e8)puts("-1");else
	printf("%d %d %d\n",a1,a2,a3);
	return 0;
}
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

int n,k;
char a[111],b[111],s[111];
bool f[1111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	f[1]=1;
	for (int i=2;i<=1000000;i++)if (!f[i]){
		long long j=i*1ll*i;
		while (j<=1000000){
			f[j]=1;
			j+=i;
		}
	}
	for (int i=1;i<=1000000;i++)if (!f[i]){
		int s=0,x=i;
		while (x){
			s=s*10+x%10;
			x/=10;
		}
		if (s!=i&&!f[s]){
			n--;
			if (!n){
				CC(i);
				return 0;
			}
		}
	}
	return 0;
}
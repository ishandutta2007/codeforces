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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int q[11],n,ans;
long long x;

bool per(int a,int b,int aa,int bb){
	return max(a,aa)<=min(b,bb);
}

int g(long long i){
		if (i<4)return 0;
		int x=sqrt(sqrt(i))+1-1e-17;
		int y=sqrt(i)+1e-17;
		for (int i=0;i<5;i++)q[i]=0;
		if (per(0,4-1,x,y))q[0]=1;
		if (per(4,4+12-1,x,y))q[1]=1;
		if (per(4+12,4+12+66-1,x,y))q[2]=1;
		if (per(4+12+66,4+12+66+6642-1,x,y))q[0]=1;
		if (per(4+12+66+6642,4+12+66+6642+43902-1,x,y))q[3]=1;
		if (per(4+12+66+6642+43902,4+12+66+6642+43902+1000000-1,x,y))q[1]=1;
		int r=0;
		while (q[r])r++;
		return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> x;
		ans^=g(x);
	}
	if (ans)puts("Furlo");else puts("Rublo");
	return 0;
}
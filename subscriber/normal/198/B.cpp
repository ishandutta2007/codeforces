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

int n,k,q1,q2,x,y,l,f[2][111111],qx[333333],qy[333333],ql[333333];
char a[2][111111];
string ans="NO";

void add(int x,int y,int l){
	if (y>=n)ans="YES";
	if (y>=n||a[x][y]=='X'||f[x][y]||l>y)return;
	f[x][y]=1;
	qx[q1]=x;
	qy[q1]=y;
	ql[q1++]=l;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&k);
	gets(a[0]);
	gets(a[1]);
	add(0,0,0);
	while (q1!=q2){
		x=qx[q2];
		y=qy[q2];
		l=ql[q2++];
		add(x,y+1,l+1);
		add(x,y-1,l+1);
		add(x^1,y+k,l+1);
	}
	CC(ans);
	return 0;
}
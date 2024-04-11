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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

char a1,a2,a3,a4;
int b1,b2,b3,b4,a[11][11];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%c%d %c%d %c%d %c%d",&a1,&b1,&a2,&b2,&a3,&b3,&a4,&b4);
	a1-='a';
	a2-='a';
	a3-='a';
	a4-='a';
	b1--;
	b2--;
	b3--;
	b4--;
	for (int i=-1;i<2;i++)for (int j=-1;j<2;j++)if (abs(i)+abs(j)==1){
		int x=a1,y=b1;
		while (x>=0&&x<8&&y>=0&&y<8){	
			if (x==a3&&y==b3)break;
			if (x!=a1||y!=b1)a[x][y]=1;
			x+=i;
			y+=j;
		}
	}
	for (int i=-1;i<2;i++)for (int j=-1;j<2;j++)if (abs(i)+abs(j)==1){
		int x=a2,y=b2;
		while (x>=0&&x<8&&y>=0&&y<8){	
			if (x==a3&&y==b3)break;
			if (x!=a2||y!=b2)a[x][y]=1;
			x+=i;
			y+=j;
		}
	}
	for (int i=-1;i<2;i++)for (int j=-1;j<2;j++)if (i||j){
		int x=a3+i;
		int y=b3+j;
		if (x>=0&&x<8&&y>=0&&y<8)a[x][y]=1;
	}
	for (int i=-1;i<2;i++)for (int j=-1;j<2;j++){
		int x=a4+i;
		int y=b4+j;
		if (x>=0&&x<8&&y>=0&&y<8&&a[x][y]==0){
			puts("OTHER");
			return 0;
		}
	}
	puts("CHECKMATE");
	return 0;
}
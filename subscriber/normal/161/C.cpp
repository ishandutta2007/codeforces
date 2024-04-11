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

int a,b,aa,bb,w[66][66][66][66];

int rec(int a,int b,int aa,int bb,int k){
	if (k<6&&w[a][b][aa][bb]!=-1)return w[a][b][aa][bb];
	if (k==1)return 1;
	int d=pw(k)-1;
	int m=pw(k-1);
	int r=0;
	if (b>=m&&bb>=m)r=max(r,min(b,bb)-max(a,aa)+1);
	if (b<m){
		if (bb<m)r=max(r,rec(a,b,aa,bb,k-1));else
		if (aa>m)r=max(r,rec(a,b,aa-m,bb-m,k-1));else{
			if (aa<=m-1)r=max(r,rec(a,b,aa,m-1,k-1));
			if (m+1<=bb)r=max(r,rec(a,b,1,bb-m,k-1));
		}
		
	}else if (a>m){
		if (bb<m)r=max(r,rec(a-m,b-m,aa,bb,k-1));else
		if (aa>m)r=max(r,rec(a-m,b-m,aa-m,bb-m,k-1));else{
			if (aa<=m-1)r=max(r,rec(a-m,b-m,aa,m-1,k-1));
			if (m+1<=bb)r=max(r,rec(a-m,b-m,1,bb-m,k-1));
		}
		
	}else{
		if (a<=m-1){
			if (bb<m)r=max(r,rec(a,m-1,aa,bb,k-1));else
			if (aa>m)r=max(r,rec(a,m-1,aa-m,bb-m,k-1));else
			if (m+1<=bb)r=max(r,rec(a,m-1,1,bb-m,k-1));
			
		}
		if (m+1<=b){
			if (bb<m)r=max(r,rec(1,b-m,aa,bb,k-1));else
			if (aa>m)r=max(r,rec(1,b-m,aa-m,bb-m,k-1));else
			if (aa<=m-1)r=max(r,rec(1,b-m,aa,m-1,k-1));
			
		}
	}
	if (k<6)w[a][b][aa][bb]=r;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a >> b >> aa >> bb;
	for (int i=0;i<65;i++)
	for (int ii=0;ii<65;ii++)
	for (int iii=0;iii<65;iii++)
	for (int iiii=0;iiii<65;iiii++)w[i][ii][iii][iiii]=-1;
	CC(rec(a,b,aa,bb,30));
	return 0;
}
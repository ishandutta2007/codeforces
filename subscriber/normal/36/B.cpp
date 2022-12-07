#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <time.h>

using namespace std;

int n,k,d;
char s[6][6],a[6][250][250];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d\n",&n,&k);
	for (int i=0;i<n;i++)gets(s[i]);
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)a[1][i][j]=s[i][j];
	d=n;
	for (int i=2;i<=k;i++){
		for (int ii=0;ii<n;ii++)for (int jj=0;jj<n;jj++)if (s[ii][jj]=='*'){
			int x=ii*d;
			int y=jj*d;
			for (int xx=x;xx<x+d;xx++)for (int yy=y;yy<y+d;yy++)a[i][xx][yy]='*';
		}else{
			int x=ii*d;
			int y=jj*d;
			for (int xx=x;xx<x+d;xx++)for (int yy=y;yy<y+d;yy++)a[i][xx][yy]=a[i-1][xx-x][yy-y];
		}
		d*=n;
	}
	for (int i=0;i<d;i++)puts(a[k][i]);
	return 0;
}
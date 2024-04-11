#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
const int N=300008;
int n,b[N];
pair<int,int>a[N];
int maxx(int x,int y){if(x>y)y=x;return y;}
int main(void)
{
	int i,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&k);a[i]=mp(k,i);}
	sort(a+1,a+1+n);
	k=0;
	for(i=1;i<=n;i++){k=maxx(k,a[i].X);b[a[i].Y]=k;k++;}
	for(i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}
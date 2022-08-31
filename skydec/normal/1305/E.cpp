#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=5005;
int n,m;
int a[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		if(m>=(i-1)/2){
			m-=(i-1)/2;
			a[i]=i;
		}
		else{
			int g=m*2+1;
			a[i]=2*i-1-2*m;
			m=0;
			//fill i+1...n
			int P=a[i];
			P=((P+3)/4)*4;
			a[i+1]=2*P+1;
			rep(j,i+2,n){
				a[j]=a[j-1]+P;
			}
			break;
		}
	}
	if(m>0){
		printf("-1\n");
		return 0;
	}
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}
/*
LANG: C++
ID: AnilKishore (RedAnt/FlyingAnt)
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define FILL(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI(x) scanf("%d",&x)

int isPrime(int n)
{
	if(n<=1) return 0;
	if(n==2||n==3) return 1;
	if(n%2==0) return 0;
	for(int i=3;i*i<=n;i+=2) if(n%i==0) return 0;
	return 1;
}

int isP[11111],Prime[10005];;
int isA[11111];	

int main()
{
	int n,i,j,k,kk=0;
	for(i=0,j=0;i<=1111;i++) if(isPrime(i)){ Prime[j++] = i; isP[i]=1; }

	SI(n); SI(k);
	for(i=0;i<j;i++) isA[Prime[i]+Prime[i+1]+1] = 1;

	for(i=2;i<=n;i++) if( isP[i] && isA[i]) kk++;

	puts(kk>=k ? "YES" : "NO");

	return 0;
}
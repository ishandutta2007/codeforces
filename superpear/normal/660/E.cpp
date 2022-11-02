#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int bigp=1000000007;

int N,M;
int fac[1000005];

int powc(int a,int b)
{
	if (b==0) return 1;
	int d=powc(a,b/2);
	d=(LL)d*d%bigp;
	if (b%2==1) d=(LL)d*a%bigp;
	return d;
}

int C(int M,int N)
{
	return fac[M]*(LL)powc(fac[N],bigp-2)%bigp*(LL)powc(fac[M-N],bigp-2)%bigp;
}

int main()
{
	scanf("%d %d",&N,&M);
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=(LL)fac[i-1]*i%bigp;
	int ans=1;
	int mc=(LL)(M-1)*powc(M,bigp-2)%bigp,ec=1;
	for (int t=0;t<=N-1;t++)
	{
		ans=(ans+(LL)ec*C(N,N-t-1))%bigp;
		ec=(LL)ec*mc%bigp;
	}
	cout<<(LL)ans*powc(M,N)%bigp<<endl;
	
	return 0;
}
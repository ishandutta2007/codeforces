#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int L=61;
const int N=100050;
const int M=2*N;
int cnt[M];
int main()
{
	ll n;
	int i,k,j;
	scanf("%I64d %i",&n,&k);
	for(i=0;i<L;i++) cnt[i+N]=(n>>i)&1;
	int sum=0;
	for(i=0;i<L;i++) sum+=cnt[i+N];
	if(sum>k) return printf("No\n"),0;
	int fir=0;
	for(i=0;i<L;i++) if(cnt[i+N]){ fir=i+N;}
	for(;sum<k;)
	{
		if(cnt[fir]>k-sum) break;
		cnt[fir]--;
		cnt[fir-1]+=2;
		if(!cnt[fir]) fir--;
		sum++;
	}
	for(i=0;i<M;i++) if(cnt[i]){ fir=i;break;}
	for(;sum<k;sum++)
	{
		cnt[fir]--;
		cnt[fir-1]+=2;
		fir--;
	}
	printf("Yes\n");
	for(i=L-1+N;i;i--) for(j=0;j<cnt[i];j++) printf("%i ",i-N);
	return 0;
}
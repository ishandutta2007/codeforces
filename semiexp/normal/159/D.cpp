#include <cstdio>
#include <cstring>

using namespace std;
typedef long long i64;

char in[3000]; int N;
int flg[2001][2001];
int right[2001], left[2001];

int determine(int l, int r)
{
	if(flg[l][r]==-1){
		if(r-l<=1) return flg[l][r] = 1;
		flg[l][r] = (in[l]==in[r-1]?1:0) & determine(l+1, r-1);
	}
	return flg[l][r];
}

int main()
{
	scanf("%s", in);
	N = strlen(in);
	for(int i=0;i<=N;i++){
		right[i] = left[i] = 0;
		for(int j=0;j<=N;j++) flg[i][j] = -1;
	}

	for(int i=0;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(determine(i, j)){
				right[j]++;
				left[i]++;
			}
	for(int i=1;i<=N;i++) right[i] += right[i-1];

	i64 ret = 0;
	for(int i=0;i<=N;i++) ret += (i64)left[i] * right[i];
	printf("%I64d\n", ret);
	return 0;
}
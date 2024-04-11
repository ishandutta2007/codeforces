#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long i64;

int tr(char p, char q)
{
	if(p=='R'&&q=='B') return 0;
	if(p=='R'&&q=='G') return 1;
	if(p=='G'&&q=='B') return 2;
	if(p=='B'&&q=='R') return 3;
	if(p=='G'&&q=='R') return 4;
	if(p=='B'&&q=='G') return 5;
	return -1;
}

struct finder
{
	static const int DEPTH=20, N=1<<20;
	int data[N*2][6];

	finder()
	{
	}

	void init(char* C, int len)
	{
		for(int i=0;i<N;i++){
			for(int j=0;j<6;j++) data[i+N][j] = 0;
		}
		for(int i=1;i<len;i++){
			int val = tr(C[i-1], C[i]);
			if(val!=-1) data[i+N][val] = 1;
		}
		for(int i=N-1;i>0;i--){
			for(int j=0;j<6;j++) data[i][j] = data[i*2][j] + data[i*2+1][j];
		}
	}

	int query(int L, int R, int type)
	{
		if(type==-1) return 0;

		L += N;
		R += N;
		int ret = 0;

		while(L!=R){
			if(L&1) ret += data[L++][type];
			if(R&1) ret += data[--R][type];

			L >>= 1; R >>= 1;
		}

		return ret;
	}
};

char S[1000005], T[1000005];
int nS, nT;
finder F;

int main()
{
	scanf("%s%s", S, T);
	nS = strlen(S);
	nT = strlen(T);

	F.init(T, nT);

	int left=0, right=0;
	i64 ret = 0;

	for(int i=0;i<nS;i++){
		while(right<nT-1 && S[i] != T[right]) right++;

		//calc
		ret += right-left+1 - (i==0 ? 0 : F.query(left, right+1, tr(S[i], S[i-1])));

		//last
		if(S[i] == T[left]) left++;
		if(right<nT-1) right++;

		if(left >= nT) break;
	}

	printf("%I64d\n", ret);

	return 0;
}
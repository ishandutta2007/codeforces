#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int A[1000][1000], B[1000][1000], As[1000], Bs[1000];

int main()
{
	int x, y;
	for(int i=0;i<1000;i++){
		As[i] = Bs[i] = 0;
		for(int j=0;j<1000;j++){
			A[i][j] = B[i][j] = 0;
		}
	}

	scanf("%d%d", &N, &M);
	for(;N--;){
		scanf("%d%d", &x, &y);
		As[--y]++;
		A[y][--x]++;
	}
	for(;M--;){
		scanf("%d%d", &x, &y);
		Bs[--y]++;
		B[y][--x]++;
	}

	int u=0, v=0;
	for(int i=0;i<1000;i++){
		u += min(As[i], Bs[i]);
		for(int j=0;j<1000;j++){
			v += min(A[i][j], B[i][j]);
		}
	}
	printf("%d %d\n", u, v);
	return 0;
}
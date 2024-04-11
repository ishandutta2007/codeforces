#include<cstdio>
#include<algorithm>
using namespace std;

int N, v[1000];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++) scanf("%d", v+i);
	sort(v, v+N);

	int ret = 0;
	for(int i=1;i<N;i++){
		if(v[i]==0) continue;
		if(v[i]==v[i-1]) ++ret;
		if(i>=2 && v[i]==v[i-1] && v[i-1]==v[i-2]){
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", ret);

	return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, X, Y;
int a[100000], b[100000];

int main()
{
	scanf("%d%d%d%d", &N, &M, &X, &Y);
	for(int i=0;i<N;i++) scanf("%d", a+i);
	for(int i=0;i<M;i++) scanf("%d", b+i);

	vector<int> r1, r2;
	int p=0;
	for(int i=0;i<N;i++){
		while(a[i]-X > b[p] && p<M) p++;
		if(p==M) break;
		if(a[i]+Y < b[p]){
			continue; //too large
		}
		if(a[i]-X <= b[p] && b[p] <= a[i]+Y){
			r1.push_back(i+1);
			r2.push_back(p+1);
			p++;
		}
	}
	printf("%d\n", r1.size());
	for(int i=0;i<r1.size();i++) printf("%d %d\n", r1[i], r2[i]);
	return 0;
}
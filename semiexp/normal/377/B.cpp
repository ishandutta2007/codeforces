#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long i64;

#define MOD 1000000009
#define ADD(X, Y) ((X) = ((X) + (Y)) % MOD)

int N, M, S;
int A[100000], B[100000], C[100000];
pair<int, int> task[100000];
pair<int, pair<int, int> > st[100000]; //abil, cost, who

int who[100000];

bool test(int days)
{
	i64 cost = 0;
	priority_queue<pair<int, pair<int, int> > > stud; //-cost, rem, who
	int ptr = 0;

	for(int i=0;i<M;i++){
		while(ptr < N && st[ptr].first >= task[i].first){
			stud.push(make_pair(-st[ptr].second.first, make_pair(days, st[ptr].second.second)));
			++ptr;
		}

		if(stud.empty()) return false;

		pair<int, pair<int, int> > tmp = stud.top(); stud.pop();

		//printf("%d:%d ", task[i].second, tmp.second.second+1);
		who[task[i].second] = tmp.second.second + 1;

		cost -= tmp.first;
		tmp.second.first--;
		tmp.first = 0;
		if(tmp.second.first) stud.push(tmp);
	}

	return (cost <= (i64)S);
}

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for(int i=0;i<M;i++) scanf("%d", A+i);
	for(int i=0;i<N;i++) scanf("%d", B+i);
	for(int i=0;i<N;i++) scanf("%d", C+i);
	for(int i=0;i<M;i++) task[i] = make_pair(A[i], i);
	for(int i=0;i<N;i++) st[i] = make_pair(B[i], make_pair(C[i], i));

	sort(task, task+M);
	reverse(task, task+M);
	sort(st, st+N);
	reverse(st, st+N);

	int left=1, right=100010;
	while(left < right){
		int mid = (left+right)/2;
		if(test(mid)){
			right = mid;
		}else{
			left = mid+1;
		}
	}

	if(right > M){
		puts("NO");
		return 0;
	}
	puts("YES");
	test(left);
	for(int i=0;i<M;i++){
		printf("%d%c", who[i], (i==M-1) ? '\n' : ' ');
	}

	return 0;
}
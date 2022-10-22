#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M;
string str1[30], str2[30];
LL A[303030];

int main(){
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) cin >> str1[i];
	for (int i=0; i<M; i++) cin >> str2[i];

	scanf("%d", &TC);
	while (TC--){
		int x;
		scanf("%d", &x);
		x--;
		cout<<str1[x%N]<<str2[x%M]<<'\n';
	}
	return 0;
}
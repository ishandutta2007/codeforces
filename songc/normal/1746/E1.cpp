#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define pb push_back
#define MOD 1000000007
#define INF (1ll<<60);
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
vector<int> S;
vector<int> A, B, C;

bool ask(vector<int> &v){
	printf("? %d", v.size());
	for (int x : v) printf(" %d", x);
	printf("\n");
	fflush(stdout);
	char str[5];
	scanf("%s", str);
	return str[0] == 'Y';
}

void answer(int a, int b){
	printf("! %d\n", a);
	fflush(stdout);
	char str[5];
	scanf("%s", str);
	if (str[1] == ')') return;
	printf("! %d\n", b);
	fflush(stdout);
	scanf("%s", str);
}

void Minus(vector<int> &a, vector<int> &b, vector<int> &c){
	int i=0;
	c.clear();
	for (int x : a){
		while (i < b.size() && b[i] < x) i++;
		if (i >= b.size() || b[i] != x) c.pb(x);
	}
}

int main(){
	scanf("%d", &N);
	if (N == 1){
		answer(1, 1);
		return 0;
	}
	for (int i=1; i<=N; i++) S.pb(i);
	if (N > 3){
		for (int i=1; i<=N/2; i++) A.pb(i);
		if (!ask(A)) Minus(S, A, B), swap(A, B);
	}
	while (S.size() > 3){
		int i=0;
		Minus(S, A, B); 
		i = B.size()/2;
		while (i--) B.pop_back();
		int n=B.size();
		for (int i=0; i<A.size()/2; i++) B.pb(A[i]);
		inplace_merge(B.begin(), B.begin()+n, B.end());
		if (!ask(B)){
			Minus(S, B, C);
			swap(B, C);
		}
		S.clear();
		for (int x : A) S.pb(x);
		for (int x : B) S.pb(x);
		inplace_merge(S.begin(), S.begin()+A.size(), S.end());
		S.erase(unique(S.begin(), S.end()), S.end());
		swap(A, B);
	}
	if (S.size() == 3){
		int a=S[0], b=S[1], c=S[2];
		vector<int> v;
		v.pb(a);
		if (ask(v)){
			v.clear();
			v.pb(b);
			if (!ask(v)) S[1] = c;
		}
		else{
			if (ask(v)){
				v.clear();
				v.pb(b);
				if (!ask(v)) S[1] = c;
			}
			else S[0] = c;
		}
	}
	answer(S[0], S[1]);
	return 0;
}
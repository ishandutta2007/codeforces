#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN];
PII b[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int tmp = a[0];
	for (int i = 1; i < n; i++)
		a[i-1] += a[i];
	a[n-1] += tmp;
	for (int i = 0; i < n; i++){
		b[i] = PII(a[i], i);
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++){
		a[b[i].second] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], " \n"[i + 1 == n]);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}
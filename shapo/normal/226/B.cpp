#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>

#define maxn 200000

using namespace std;

long long ansQuery[maxn];
long long curNum[maxn];
long long sum[maxn];
int n;

bool cmp(const long long &a, const long long &b){return(a > b);}

int main(){
	//ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int aa;
		scanf("%d", &aa);
		curNum[i] = aa;
	}
	sort(curNum + 1, curNum + n + 1, cmp);
	sum[0] = 0;
	for(int i = 1; i <= n; ++i){
		sum[i] = sum[i - 1] + curNum[i];
		//printf("curNum[%d] = %lld\n", i, curNum[i]);
	}
	for(int i = 1; i <= 100000; ++i){
		long long curRep = 1;
		int curPos = 2;
		long long curI = i;
		ansQuery[i] = 0;
		while(curPos + curI - 1 <= n){
			ansQuery[i] += curRep * (sum[curPos + curI - 1] - sum[curPos - 1]);
			++curRep;
			curPos += curI;
			curI = curI * (long long)i;
		}
		/*if(i <= n)
			printf("ansQuery[%d] = %lld\n", i, ansQuery[i]);*/
		ansQuery[i] += curRep * (sum[n] - sum[curPos - 1]);
	}
	int q, Request;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i){
		scanf("%d", &Request);
		cout << ansQuery[Request] << '\n';
	}
	return 0;
}
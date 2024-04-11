#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,m;
int x[N];
int cnt;
void print(int x) {
	if(x==1) printf("sjfnb");
	else printf("cslnb");
}
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	sort(x, x+n);
	if(n>1 && x[1]==0) {print(2); return 0;}
	for(int i=0; i<n-1; i++) {
		if(x[i]==x[i+1]) {
			x[i]--;
			for(int j=0; j<n-1; j++) {
				if(x[j]==x[j+1]) {
					print(2);
					return 0;
				}
			}
			cnt++;
			break;
		}
	}
	ll sum=0;
	for(int i=0; i<n; i++) sum+=x[i];
	sum-=1ll*n*(n-1)/2;
	sum+=cnt;
	if(sum&1) print(1);
	else print(2);
}
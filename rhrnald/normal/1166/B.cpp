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
int x,y;
char p[5]={'a', 'e', 'i', 'o', 'u'};
char ans[10000][10000];
int main(void){
	scanf("%d", &n);
	for(int i=5; i*i<=n; i++) {
		if(!(n%i)) {x=i, y=n/i; break;}
	}
	if(!x) {printf("-1"); return 0;}

	int cur=0;
	for(int i=0; i<x; i++) {
		int c=cur;
		for(int j=0; j<y; j++) {
			ans[i][j]=c%5;
			c++;
		}
		cur++;
	}
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			printf("%c", p[ans[i][j]]);
}
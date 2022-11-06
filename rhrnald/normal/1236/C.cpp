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
int main(void){
	scanf("%d", &n);
	bool b;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(b) x[i*n+j]=j;
			else x[i*n+j]=n-1-j;
		}
		b=!b;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n*n; j++) {
			if(x[j]==i) printf("%d ", j+1);
		}
		printf("\n");
	}
}
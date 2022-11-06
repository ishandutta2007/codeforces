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
vector<int> v1, v2;
int main(void){
	scanf("%d", &n);

	if(n&1) {
		printf("YES\n");
		bool flag=true;
		for(int i=1; i<=n; i++) {
			if(flag) {
				v1.push_back(i+i-1);
				v2.push_back(i+i);
			} else {
				v1.push_back(i+i);
				v2.push_back(i+i-1);
			}
			flag=!flag;
		}
		for(int e : v1) printf("%d ", e);
		for(int e : v2) printf("%d ", e);
	} else {
		printf("NO");
	}
}
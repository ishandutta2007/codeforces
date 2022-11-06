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
string _s;
int s[N];
int l[N];
int cur[N];
void proc() {
	cin >> _s;
	n=sz(_s);
	for(int i=0; i<n; i++) s[i]=_s[i]=='1';
	
	int c=0;
	int ans=0;
	for(int i=0; i<n; i++) {
		if(s[i]) {
			int num=0;
			for(int j=0; i+j<n; j++) {
				num=num+num+s[i+j];
				if(num-j-1>c) break;
				else ans++;
			}
			c=0;
		}
		else c++;
	}
	printf("%d\n", ans);
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}
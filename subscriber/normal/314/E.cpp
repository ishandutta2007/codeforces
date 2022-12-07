#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n;
char a[1000111];
unsigned int f[200001];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	gets(a);
	f[0]=1;
	int d = 0;
	int m = 1;
	for (int i=0;i<n;i++) {
		if (a[i] == '?') {
 			if (d == 1){
 				for (int j = 1; j < m; j += 2) {
 					f[j - 1] += f[j];
 					f[j + 1] += f[j];
 					f[j] = 0;
 				}
 			} else {
 				f[1] += f[0];
 				f[0] = 0;
 				for (int j = 2; j < m; j += 2) {
 					f[j - 1] += f[j];
 					f[j + 1] += f[j];
 					f[j] = 0;
 				}
 			}
		} else{
			for (int j=d;j<m;j += 2) {
				f[j+1] += f[j];
				f[j] = 0;
			}
		}
		d ^= 1;
		m ++;
		while (m - (n - i - 1) > 1) m--;
	}
	int s = 0;
	for (int i=0;i<n;i++)if (a[i] == '?') s++;
	s -= n/2;
	for (int i=0;i<s;i++)f[0] *= 25;
	cout << f[0] << endl;
	return 0;
}
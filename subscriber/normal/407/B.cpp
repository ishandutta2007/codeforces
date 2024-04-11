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
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n, p[111111];
int f[111111];

int main(){
//  freopen("1.in","r",stdin);  
//  freopen("1.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    f[0] = 2;
    for (int i = 1; i < n; i++) {
        int x = 0;
        for (int j = p[i]; j < i; j++) x = (x + f[j]) % M;
        x = (x + 2) % M;
        f[i] = x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = (ans + f[i]) % M;
    cout << ans << endl;

    return 0;
}
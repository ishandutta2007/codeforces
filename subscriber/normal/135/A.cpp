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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int n,a[111111];


int main(){
//      freopen("1.in","r",stdin);      
  //    freopen("1.out","w",stdout);    
        cin >> n;
        for (int i=1;i<=n;i++)cin >> a[i];
        a[0]=1;
        sort(a+1,a+n+1);
        if (a[n]==1)a[n-1]=2;
        for (int i=0;i<n;i++)cout << a[i] << " ";
        return 0;
}
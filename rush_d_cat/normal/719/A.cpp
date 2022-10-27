#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define INF 1e9 + 7
typedef long long ll;
using namespace std;
#define MAXN 2000 + 10
#define MAXM 2000 + 10
int a[100];
int main()
{
    int n, i;cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    if(a[n] == 15) cout << "DOWN" << endl;
    else if(a[n] == 0) cout << "UP" <<endl;
    else{
        if(n == 1) cout << -1 << endl;
        else{
            if(a[n] > a[n-1]) cout << "UP" << endl;
            else cout << "DOWN" << endl;
        }
    }
}
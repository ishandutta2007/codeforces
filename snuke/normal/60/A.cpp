#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iostream>
#include <sstream>
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,o,n) for(int i = o; i < n; i++)
#define drep(i,n) for(int i = n; i >= 0; i--)
#define pb push_back
typedef long long ll;
using namespace std;


int main () {
    int n, m, c, l, r = 1;
    char a[5], b[6];
    string s;
    
    scanf("%d%d",&n,&m);
    l = n;
    
    rep(i,m){
        scanf("%s%s%s%s%d",a,a,b,a,&c);
        s = b;
        if(s == "left"){
            l = min(l,c-1);
        } else {
            r = max(r,c+1);
        }
    }
    
    if(l < r) puts("-1"); else{
        printf("%d\n",l-r+1);
    }
    
    return 0;
}
//In the name of God
//Not my code
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <limits.h>
#include <algorithm>
#include <deque>
#define inf 0x3f3f3f3f
#define nmax 100010
#define eps 1e-12
#define pi 3.1415926536
using namespace std;
int n,m,i,j,x,y,tip;
char s[nmax];
vector <int> g[30];
vector <int>::iterator it;
int main(){
//freopen("1.in","r",stdin);
scanf("%d %d %s",&n,&m,s+1);
for (i=1;i<=n;i++)
    g[s[i]-96].push_back(i);
for (i=1;i<=m;i++) {
    scanf("%d %d %d",&x,&y,&tip);
    if (tip==0) {
        int k=x;
        for (int l=26;l>=1;l--) {
            int st=lower_bound(g[l].begin(),g[l].end(),x)-g[l].begin();
            int dr=upper_bound(g[l].begin(),g[l].end(),y)-g[l].begin();
            for (;st<dr;st++) {
                g[l][st]=k; k++;
            }
        }
    } else
    {
        int k=x;
        for (int l=1;l<=26;l++) {
            int st=lower_bound(g[l].begin(),g[l].end(),x)-g[l].begin();
            int dr=upper_bound(g[l].begin(),g[l].end(),y)-g[l].begin();
            for (;st<dr;st++) {
                g[l][st]=k; k++;
            }
        }
    }
}
for (i=1;i<=26;i++) {
    for (j=0;j<g[i].size();j++)
        s[g[i][j]]=char(i+96);
}
puts(s+1);
return 0;
}
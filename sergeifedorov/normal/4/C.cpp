#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

char s[10000];
string nm;
map<string,int> h;
int n;

int main(){
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    scanf("%d\n", &n);
    forn(i,n){
        gets(s);
        nm = s;
        int q = h[nm];
        h[nm] ++;
        if (q == 0)
            puts("OK");
        else{
            printf("%s%d\n",s,q);
        }
    }   

    return 0;   
}
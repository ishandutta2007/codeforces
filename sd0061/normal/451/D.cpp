#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 100005;
int n;
char s[N];
int cnt[2][2];

void work() {
    scanf("%s" , s);
    n = strlen(s);
    LL ansE = 0 , ansO = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int x = i & 1 , y = s[i] - 'a';
        ++ cnt[x][y];
        ansE += cnt[!x][y];
        ansO += cnt[x][y];
    }
    cout << ansE << ' ' << ansO << endl;
}

int main(){
    work();
    return 0;
}
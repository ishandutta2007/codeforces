#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
vector<int> v[1002];
char s[1002], t[1002];
int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", s+1);
    scanf("%s", t+1);

    int ans = n, id = 1;
    for(int i=1;i<=m-n+1;i++) {
        int temp = 0;
        for(int j=1;j<=n;j++) {
            if(s[j] != t[i+j-1]) {
                temp++;
                v[i].push_back(j);
            }
        }
        if(temp < ans) {
            id = i;
            ans = temp;
        }
    }
    printf("%d\n", ans);
    for(int i=0;i<(int)v[id].size()-1;i++) {
        printf("%d ", v[id][i]);
    }
    if(ans != 0) {
        printf("%d\n", v[id][(int)v[id].size()-1]);
    }
}
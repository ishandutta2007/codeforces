#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int n;
int d[N] , s[N];
queue<int> Q;
vector< pair<int , int> > res;
int main()
{
    int i , j , x , y,  z;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&d[i] , &s[i]);
        if (d[i] == 1) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        if (d[x] == 1) {
            res.push_back(make_pair(x , s[x]));
            s[s[x]] ^= x;
            if (-- d[s[x]] == 1) {
                Q.push(s[x]);
            }
        }
    }
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d %d\n" , res[i].first , res[i].second);
    return 0;
}
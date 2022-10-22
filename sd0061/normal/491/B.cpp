#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , C , H;
int mx[4];
void work() {
    int i , x , y;
    for (i = 0 ; i < 4 ; ++ i)
        mx[i] = 0x80000000;
    scanf("%d%d",&n,&m);
    scanf("%d",&C);
    for (i = 0 ; i < C ; ++ i) {
        scanf("%d%d",&x,&y);
        mx[0] = max(mx[0] , -x - y);
        mx[1] = max(mx[1] , -x + y);
        mx[2] = max(mx[2] , +x - y);
        mx[3] = max(mx[3] , +x + y);
    }
    pair<int , int> res(0x7FFFFFFF , -1);
    scanf("%d",&H);
    for (i = 0 ; i < H ; ++ i) {
        scanf("%d%d",&x,&y);
        int dis = 0x80000000;
        dis = max(dis , +x + y + mx[0]);
        dis = max(dis , +x - y + mx[1]);
        dis = max(dis , -x + y + mx[2]);
        dis = max(dis , -x - y + mx[3]);
        res = min(res , make_pair(dis , i + 1));
    }
    printf("%d\n%d\n" , res.first , res.second);
}

int main() {
    work();
    return 0;
}
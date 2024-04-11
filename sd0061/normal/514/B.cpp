#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;

int n , X , Y;
set< pair<int , int> > h;

void work() {
    scanf("%d%d%d",&n,&X,&Y);
    for (int i = 0 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d",&x,&y);
        x -= X , y -= Y;
        int z = __gcd(x , y);
        h.insert(make_pair(x / z , y / z));
    }
    cout << h.size() << endl;
}

int main() {
//    freopen("1" , "r" , stdin);

    work();
    return 0;
}
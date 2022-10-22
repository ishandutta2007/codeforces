#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m;
struct Point {
    int x , y , id;
    bool operator < (const Point& R) const {
        return make_pair(x , y) > make_pair(R.x , R.y);
    }
}p[N] , s[N];
int top;
set< pair<int , int> > res;
pair<int , int> b[N];
bool Cross(Point A , Point B , Point C) {
    return (LL) B.y * C.x * (A.x - B.x) * (A.y - C.y) < (LL)B.x * C.y * (A.y - B.y) * (A.x - C.x);
}

void work() {
    int i , x , y;
    scanf("%d",&n) , m = n;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&p[i].x , &p[i].y);
        p[i].id = i + 1;
        b[i] = make_pair(p[i].x , p[i].y);
    }
    sort(p , p + n);
    for (i = 0 ; i < n ; ++ i) {
        if (!top || p[i].y > s[top - 1].y)
            s[top ++] = p[i];
    }
    memcpy(p , s , sizeof(s));
    n = top , top = 0;
    for (i = 0 ; i < n ; ++ i) {
        while (top > 1 && Cross(s[top - 1] , s[top] , p[i]))
            -- top;
        s[++ top] = p[i];        
    }
    for (i = 1 ; i <= top ; ++ i)
        res.insert(make_pair(s[i].x , s[i].y));
    for (i = 0 ; i < m ; ++ i)
        if (res.count(b[i]))
            printf("%d " , i + 1);        
}

int main() {
    work();
    return 0;
}
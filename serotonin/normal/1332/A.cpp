#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int x,y,x1,y1,x2,y2;
        scanf("%d %d %d %d %d %d", &x,&y,&x1,&y1,&x2,&y2);

        bool yes=1;
        if(x-a+b<x1 || x+b-a>x2) yes=0;
        if(y-c+d<y1 || y-c+d>y2) yes=0;
        if(x1==x2 && (a || b)) yes=0;
        if(y1==y2 && (c || d)) yes=0;

        if(yes) puts("YES");
        else puts("NO");
    }
}
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<int> s;
int main()
{
    s.insert(1); s.insert(2);
    s.insert(4); s.insert(5);
    int x=4,y=5;
    while(x<=1000000&&y<=1000000)
    {
        int xx=x+1+y; int yy=x+1+x;
        s.insert(xx); s.insert(yy);
        x=xx; y=yy;
    }
    int n;
    scanf("%d",&n);
    if(s.find(n)!=s.end()) puts("1"); else puts("0");
}
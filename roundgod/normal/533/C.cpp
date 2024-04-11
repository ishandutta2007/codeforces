#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c,d;
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int dist1=a+b;
    int dist2=min(c,d)+max(c-d,d-c);
    if((a<=c&&b<=d)||(dist1<=dist2)) puts("Polycarp"); else puts("Vasiliy");
    return 0;
}
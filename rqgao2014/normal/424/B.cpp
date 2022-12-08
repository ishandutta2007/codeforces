#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#define sqr(x) (x)*(x)
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
using namespace std;

struct node{
    int x,y,dis,k;
}p[10001];
int n,s;
bool cmp(node x,node y){
    return x.dis<y.dis;
}

int main()
{
    scanf("%d%d",&n,&s);//cin>>n>>s;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].k);//cin>>p[i].x>>p[i].y>>p[i].k;
        p[i].dis=sqr(p[i].x)+sqr(p[i].y);
    }
    sort(p+1,p+n+1,cmp);
    if(s>=1000000){
        printf("0");return 0;
    }
    for(int i=1;i<=n;i++){
        s+=p[i].k;
        if(s<1000000) continue;
        else{
            printf("%.8f",sqrt((double)(p[i].dis)));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
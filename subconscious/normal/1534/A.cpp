#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=55,mod=1e9+7;
char a[N][N];
int n,m,T;
bool check1(){
    rep(i,n)rep(j,m)if(a[i][j]!='.'&&a[i][j]!=((i+j)%2==1?'R':'W'))return 0;
    return 1;
}
bool check2(){
    rep(i,n)rep(j,m)if(a[i][j]!='.'&&a[i][j]!=((i+j)%2==0?'R':'W'))return 0;
    return 1;
}
void put1(){
    puts("YES");
    rep(i,n)rep(j,m)a[i][j]=((i+j)%2==1?'R':'W');
    rep(i,n)puts(a[i]+1);
}
void put2(){
    puts("YES");
    rep(i,n)rep(j,m)a[i][j]=((i+j)%2==0?'R':'W');
    rep(i,n)puts(a[i]+1);
}
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d%d",&n,&m);
        rep(i,n)scanf("%s",a[i]+1);
        if(check1())put1();
        else if(check2())put2();
        else puts("NO");
    }
    return 0;
}
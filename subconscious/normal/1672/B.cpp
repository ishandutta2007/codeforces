#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef vector<int> vi;
const int N=2e5+5;
const ll inf=1e18+7;
int n,T;
char s[N];
bool check(){
    if(s[n]!='B')return 0;
    if(s[1]!='A')return 0;
    int cnt=0;
    rep(i,n){
        if(s[i]=='A')++cnt;else --cnt;
        if(cnt<0)return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%s",s+1);n=strlen(s+1);
        
        puts(check()?"YES":"NO");
    }
    return 0;
}
/*
10 5
2 8
6 7
3 7
2 10
7 10
9 5
9 1
5 3
4 5

6 5
1 5
2 1
3 5
4 3
6 5
*/
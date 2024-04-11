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
const int N=4e6+5,mod=998244353;
int a[N],n,m;
int main(){
    {
        scanf("%d%d",&n,&m);
        int now=0,cg=0,sum=0;
        rep(i,n){
            cg=(cg+a[i])%m;
            now=(sum+cg)%m;
            if(i==1)now=(now+1)%m;
            //printf("%d\n",now);
            //ki~k(i+1)-1
            for(int j=2;(ll)i*j<=n;++j){
                a[i*j]=(a[i*j]+now)%m;
                if((i+1)*j<=n)a[(i+1)*j]=(a[(i+1)*j]-now+m)%m;
            }
            sum=(sum+now)%m;
        }
        printf("%d\n",now);
    }
    return 0;
}
/*
    a b
u   i j
v   k p
*/
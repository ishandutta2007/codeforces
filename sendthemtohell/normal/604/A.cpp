#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define x first
#define y second
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int N=3228;
const int MOD=1000*1000*1000+7;

ll pw(ll a,int x){
    if(!x)
        return 1;
    if(x%2)
        return a*pw(a*a,x/2);
    return pw(a*a,x/2);
}

int id[100*1000+322];

void solve(){
    int x1=500,x2=1000,x3=1500,x4=2000,x5=2500;
    int m1,m2,m3,m4,m5;
    int w1,w2,w3,w4,w5;
    int hs,hu;
    cin>>m1>>m2>>m3>>m4>>m5;
    cin>>w1>>w2>>w3>>w4>>w5;
    cin>>hs>>hu;
    ld pts=hs*100-hu*50;
    pts += max(0.3*x1,(1-m1/250.)*x1-50*w1)+max(0.3*x2,(1-m2/250.)*x2-50*w2)+max(0.3*x3,(1-m3/250.)*x3-50*w3)+max(0.3*x4,(1-m4/250.)*x4-50*w4)+max(0.3*x5,(1-m5/250.)*x5-50*w5);
    cout<<(int)pts<<endl;
}




int main(){
    double tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL

    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //cout<<setprecision(20);
    //cout<<fixed;

    solve();

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
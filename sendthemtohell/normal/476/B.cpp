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

ll fact(int n){
    if(n)
        return n*fact(n-1);
    return 1;
}

ll pw(ll a,int x){
    if(!x)
        return 1;
    if(x%2)
        return a*pw(a,x-1);
    return pw(a*a,x>>1);
}

ll cnk(int n,int k){
    return fact(n)/fact(k)/fact(n-k);
}

void solve(){
    string a,w;
    cin>>a;
    cin>>w;
    int n=0,c=0,b=0;
    for(auto &i:a){
        if(i=='+')
            c+=1;
        if(i=='-')
            c-=1;
    }
    for(auto &i:w){
        if(i=='+')
            b+=1;
        if(i=='-')
            b-=1;
        if(i=='?')
            n+=1;
    }
    c=abs(c-b);
    if((n+c)%2 || (n+c)/2>n ){
        cout<<"0.000000000000000000000000000000000000000000000000000000000000000000000000"<<endl;
        return;
    }else{
        cout<<(ld)cnk(n,(n+c)/2)/(ld)pw(2,n)<<endl;
    }
}




int main(){
    double tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL

    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout<<setprecision(20);
    cout<<fixed;

    solve();

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
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

int gcd(int a,int b){
    if(b)
        return gcd(b,a%b);
    return a;
}

set<pair<int,int> > lines;

void solve(){
    string q;int q1=0,q2=0,n;
    cin>>n;
    cin>>q;
    for(auto &i:q){
        if(i!='4' && i!='7'){
            cout<<"NO\n";
            return;
        }
    }
    for(int i=0;i<n/2;++i){
        if(q[i]=='4')
            q1+=4;
        else
            q1+=7;
    }
    for(int i=n/2;i<n;++i){
        if(q[i]=='4')
            q2+=4;
        else
            q2+=7;
    }
    cout<<((q1==q2)? "YES":"NO")<<endl;
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
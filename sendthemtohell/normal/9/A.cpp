#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int N=3228;
const int MOD=1000*1000*1000+7;

bool vv[100*1000+322];
vector<vector<int> > g(100*1000+322);
set<int> cats;

int gcd(int a,int b){
    if(b)
        return gcd(b,a%b);
    return a;
}

void solve(){
    int a,b;
    cin>>a>>b;
    cout<<(7-max(a,b))/gcd(6,7-max(a,b))<<"/"<<6/gcd(6,7-max(a,b))<<endl;
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
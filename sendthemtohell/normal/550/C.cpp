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

void solve(){
    string s;
    cin>>s;
    string t="00"+s;
    for(int i=0;i<t.size();++i){
        for(int j=i+1;j<t.size();++j){
            for(int k=j+1;k<t.size();++k){
                string num="";
                num.pb(t[i]),num.pb(t[j]),num.pb(t[k]);
                if(atoi(num.c_str())%8 == 0){
                    cout<<"YES"<<endl;
                    cout<<atoi(num.c_str())<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
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
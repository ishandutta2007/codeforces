#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define x first
//
#define Left first.first
#define Right first.second
#define Id second
//
#define y second
#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false);
#define coutdouble cout<<setprecision(20);cout<<fixed;
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/

const int MOD=1000*1000*1000+7;
const int N=100*1000+322;

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
/*----------------------------------*/

unordered_set<char> pokemon;
unordered_map<char,int> kek;

bool good(){
    for(auto &i:pokemon){
        if(!kek[i])
            return false;
    }
    return true;
}

void solve(ld tt){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto &i:s){
        if(i!='\n'){
            kek[i]=0;
            pokemon.insert(i);
        }
    }
    int p1=0,p2=0,mn=n;
    while(p2<n){
        ++p2;
        ++kek[s[p2-1]];
        if(!good())
            continue;
        while(good()){
            --kek[s[p1]];
            ++p1;
        }
        mn=min(mn,p2-p1+1);
    }
    cout<<mn<<endl;;
}




int main(){
    ld tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #else
//        freopen("","r",stdin);
//        freopen("","w",stdout);
    #endif // LOCAL

    speedup
//    coutdouble

    solve(tt);

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL

    return 0;
}
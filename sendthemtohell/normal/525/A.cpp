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

char lower(char a){
    return a-'A'+'a';
}

void solve(){
    map<char,int> key;
    for(char i='a';i<='z';++i)
        key[i]=0;
    int ans=0;
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(auto &i: s){
        if(i=='\n')
            break;
        if(i>='a' && i<='z')
            ++key[i];
        else if(key[lower(i)])
            key[lower(i)]-=1;
        else
            ++ans;
    }
    cout<<ans<<endl;
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
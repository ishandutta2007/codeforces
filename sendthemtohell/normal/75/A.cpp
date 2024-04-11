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

int arr[100*1000+322];

void solve(){
    string a,b,c;
    cin>>a>>b;
    c=to_string( atoi(a.c_str()) + atoi(b.c_str()) ) ;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i=0;i<a.size();){
        if(a[i] == '0')
            a.erase(a.begin()+i);
        else
            ++i;
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i=0;i<b.size();){
        if(b[i] == '0')
            b.erase(b.begin()+i);
        else
            ++i;
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i=0;i<c.size();){
        if(c[i] == '0')
            c.erase(c.begin()+i);
        else
            ++i;
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    cout<< (((atoi(a.c_str()) + atoi(b.c_str())) == (atoi(c.c_str()))) ? "YES" : "NO");
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
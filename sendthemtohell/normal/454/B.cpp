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
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int mi=100*1000+322,miN=-1,good=1;
    for(;good<n;++good)
        if(arr[good]!=arr[good-1])
            break;
    if(good==n){
        cout<<0<<endl;
        return;
    }
    for(int i=0;i<n;++i){
        if(mi>arr[(good+i)%n]){
            mi=arr[(good+i)%n];
            miN=(good+i)%n;
        }
    }
    //cout<<miN<<endl;
    for(int i=1;i<n;++i){
        if(arr[(miN+i)%n]<arr[(miN+i-1)%n]){
            cout<<-1<<endl;
            return;
        }
    }
    if(miN)
        cout<<n-miN<<endl;
    else
        cout<<0<<endl;
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
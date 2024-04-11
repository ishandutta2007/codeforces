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

void solve(){
    int n;
    int km=0;
    cin>>n;
    vector< pair<int,int> > ja;
    for(int i=0;i<n;++i){
        int coord,cnt;
        cin>>coord>>cnt;
        ja.pb({coord,cnt});
        if(coord < 0)
            ++km;
    }
    sort(ja.begin(),ja.end());
    if(km==0){
        cout<<ja[0].y<<endl;
        return;
    }else if(km==n){
        cout<<ja[n-1].y<<endl;
        return;
    }

    int l1 = 2*km % n;
    int m1=0;
    if(l1 <= km){
        for(int i=l1; i<n;++i)
            m1+=ja[i].second;
    }else{
        for(int i=0; i<=l1;++i)
            m1+=ja[i].second;
    }
    int l2 = 2*km % n;
    int m2=0;
    if(l2==0)
        l2=n;
    if(l2 < km){
        for(int i=l2-1; i<n;++i)
            m2+=ja[i].second;
    }else{
        for(int i=0; i<l2;++i)
            m2+=ja[i].second;
    }
   // cout<<l1<<"  "<<l2<<"  "<<km<<endl;
    cout<<max(m1,m2)<<endl;
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
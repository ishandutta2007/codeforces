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


void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > rating (n);
    for(int i=0;i<n;++i){
        int r;
        cin>>r;
        rating[i].first=r;
        rating[i].second=i;
    }
    sort(rating.begin(),rating.end());
    vector<int> ans(n);
    ans[rating[0].second]=rating[0].first;
    for(int i=1;i<n;++i){
        rating[i].first=max(rating[i].first,rating[i-1].first+1);
        ans[rating[i].second]=rating[i].first;
    }
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
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
    vector<string> team;
    vector<int> score;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string cg;
        int it;
        cin>>cg;
        for(it=0;it<team.size();++it){
            if(team[it]==cg)
                break;
        }
        if(it == team.size())
            team.pb(cg),score.pb(1);
        else
            score[it]+=1;
    }
    int mx=0;
    if(team.size()==2 && score[1]>score[0])
        ++mx;
    cout<<team[mx]<<endl;
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
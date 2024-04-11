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
    string beg,fin;
    cin>>beg;
    cin>>fin;
    pair<int,int> start,gohere;
    vector<string> ans;
    start.x=(int)(beg[0]-'a'+1);
    start.y=(int)(beg[1]-'1'+1);
    gohere.x=(int)(fin[0]-'a'+1);
    gohere.y=(int)(fin[1]-'1'+1);
    while(start.x < gohere.x && start.y <  gohere.y){
        ans.pb("RU");
        ++start.x;
        ++start.y;
    }
    while(start.x > gohere.x && start.y <  gohere.y){
        ans.pb("LU");
        --start.x;
        ++start.y;
    }
    while(start.x < gohere.x && start.y >  gohere.y){
        ans.pb("RD");
        //cout<<"RD"<<endl;
        ++start.x;
        --start.y;
    }
    while(start.x > gohere.x && start.y > gohere.y){
        ans.pb("LD");
        //cout<<"LD"<<endl;
        --start.x;
        --start.y;
    }
    while(start.y < gohere.y){
        ans.pb("U");
        //cout<<"U"<<endl;
        ++start.y;
    }
    while(start.y > gohere.y){
        ans.pb("D");
        //cout<<"D"<<endl;
        --start.y;
    }
    while(start.x < gohere.x){
        ans.pb("R");
        //cout<<"R"<<endl;
        ++start.x;
    }
    while(start.x > gohere.x){
        ans.pb("L");
        //cout<<"L"<<endl;
        --start.x;
    }
    cout<<ans.size()<<endl;
    for(auto &i:ans)
        cout<<i<<endl;
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
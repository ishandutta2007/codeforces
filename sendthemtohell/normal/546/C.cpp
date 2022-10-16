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
unordered_set<ll> vv;

ll hash_vector(vector<int> v1,vector<int> v2){
    ll ans=0;int i=0;
    for(;i<v1.size();++i){
        ans += 1LL*v1[i]*pw(10,i);
    }
    for(;i<v2.size();++i){
        ans += 1LL*v2[i]*pw(10,i);
    }
    return ans+1LL*v1.size()*1000*1000*1000*1000*1000;
}

void solve(ld tt){
    int n,cnt=0;
    cin>>n;
    int k1;
    cin>>k1;
    vector<int> v1;
    for(int i=0;i<k1;++i){
        int nxt;
        cin>>nxt;
        v1.pb(nxt);
    }
    int k2;
    cin>>k2;
    vector<int> v2;
    for(int i=0;i<k2;++i){
        int nxt;
        cin>>nxt;
        v2.pb(nxt);
    }
    while(true){
        if(((ld)clock()-tt)/CLOCKS_PER_SEC>1.9){
            cout<<-1<<endl;
            return;
        }
        if(v1.empty()){
            cout<<cnt<<" "<<2<<endl;
            return;
        }
        if(v2.empty()){
            cout<<cnt<<" "<<1<<endl;
            return;
        }
        ++cnt;
        if(vv.count(hash_vector(v1,v2))){
            cout<<-1<<endl;
            return;
        }
        vv.insert(hash_vector(v1,v2));
        int card1=v1.front(),card2=v2.front();
        v1.erase(v1.begin()),v2.erase(v2.begin());
        if(card1 > card2)
            v1.pb(card2),v1.pb(card1);
        if(card1 < card2)
            v2.pb(card1),v2.pb(card2);
/*        cout<<hash_vector(v1,v2)<<endl;
        for(auto &i: v1)
            cout<<i<<" ";
        cout<<"- v1 after "<<cnt<<endl;
        for(auto &i: v2)
            cout<<i<<" ";
        cout<<"- v2 after "<<cnt<<endl;
*/    }
}




int main(){
    ld tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL

    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //cout<<setprecision(20);
    //cout<<fixed;

    solve(tt);

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
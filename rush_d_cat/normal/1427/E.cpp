#include <bits/stdc++.h>
#include <assert.h>
#include<random>
#include<ctime>
using namespace std;
typedef long long LL;
std::mt19937 rnd(0);
const int B = 64;
LL p[63];
 
vector<LL> v[B];
map<LL,int> mp;
bool can_ins(LL x) {
    mp.clear();
    for (int i = 62; i >= 0; i --) if ((x >> i) & 1) {
        if ( p[i] ) {
            x ^= p[i]; for(auto x: v[i]) mp[x] ++;
        } else {
            return true;
        }
    }    
    assert(x==0);
    return false;
}
void insert(LL x) {
    //printf("!! %lld\n", x % 123);
    LL val = x;
    vector<LL> tmp; tmp.push_back(x);
    for (int i = 62; i >= 0; i --) if ((x >> i) & 1) {
        if ( p[i] ) {
            x ^= p[i]; for(auto y: v[i]) tmp.push_back(y);
        } else {
            p[i] = x; 

            map<LL,int> mp_;
            for(auto x:tmp) mp_[x]++;
            tmp.clear();
            for(auto p:mp_) {
                if(p.second%2==1){
                    tmp.push_back(p.first);
                }
            }
            v[i]=tmp;
            break;
        }
    }
} 
void gen(vector<LL> vec, LL x) {
    LL now = x;
    vector< pair<pair<LL,LL>,int> > ans;
    ans.push_back(make_pair(make_pair(x, x),1));
    for (int i = 1; i <= 30; i ++) {
        ans.push_back(make_pair(make_pair(now,now),0)); now*=2;
    }   
    for(auto need: vec) {
        LL B = need / x;
        LL val = 0;
        for(int i=0;i<30;i++){
            if(B>>i&1) {
                ans.push_back(make_pair(make_pair(val, (1LL<<i) * x),0));
                val += (1LL<<i) * x;
            }
        }
    }
    LL val=0;
    for(auto x:vec) {
        ans.push_back(make_pair(make_pair(val,x),1));
        val^=x;
    }
    printf("%d\n", ans.size());
    LL las = -1;
    for(auto p:ans){
        if(p.second==0){
            printf("%lld + %lld\n", p.first.first,p.first.second); //vis[p.first.first + p.first.second]  = 1;
            las = p.first.first + p.first.second;
        }else{ 
            printf("%lld ^ %lld\n", p.first.first,p.first.second); //vis[p.first.first ^ p.first.second]  = 1;
            las = p.first.first ^ p.first.second;
        }
    }
    assert(las == 1);
}
 
void test(LL x) {
    srand(x);
    for(int i=1;i<=94000;i++){
        insert(x*(1LL*rnd()%10000000LL)); 
        if(can_ins(1)==false) {
            vector<LL> res;
            for(auto p:mp) {
                if(p.second%2) {
                    res.push_back(p.first);
                }
            }
            gen(res, x);
            return;
        }
    }
    //printf("x=%lld\n", x);
}
int main() {
    int x; cin>>x; test(x); return 0;
}
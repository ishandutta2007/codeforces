#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
using namespace std;


bool judge_prime(long long n){
    for(int i=2;(long long)i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return n!= 1;
}
#define MAX_N 2000050
bool is_prime[MAX_N];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}
bool large_check(ll a,int c,ll X){
    rep(zz,c){
        X /= a;
    }
    if(X==0)return true;
    return false;
}
bool equal_check(ll a,int c,ll X){
    rep(zz,c){
        if(X%a!=0)return false;
        X /= a;
    }
    if(X==1)return true;
    return false;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;   
    if(k==1){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> a(n);
    sieve(1000010);
    rep(i,n){
        cin >> a[i];
    }
    unordered_map<ll,vector<int> > mp;
    rep(i,n){
        rep(j,60){
            ll X = a[i];
            if(j==0){
                if(X >= 1000000000)continue;
                if(X <= 1000000){
                    if(is_prime[X]){
                        mp[X].push_back(i);
                        break;
                    }
                }else{
                    if(judge_prime(X)){
                        mp[X].push_back(i);
                        break;
                    }
                }
            }else{
                int c = j+1;
                ll ok = 1000000000LL;
                ll ng = 0;
                while(ok-ng>1){
                    ll mid = (ok+ng)/2;
                    if(large_check(mid,c,X)){
                        ok = mid;
                    }else{
                        ng = mid;
                    }
                }
                ok--;
                if(equal_check(ok,c,X)){
                    if(ok <= 1000000){
                        if(is_prime[ok]){
                            mp[ok].push_back(i);
                            break;
                        }
                    }else{
                        if(judge_prime(ok)){
                            mp[ok].push_back(i);
                            break;
                        }
                    }
                }
            }
        }
    }
    set<ll> st;
    bool flag =0;
    for(auto x:mp){
        // cerr << x.first << " " << x.second.size() << endl;
        if(x.second.size()>=2){
            st.insert(x.first);
        }
        if(x.second.size()>=3){
            flag = 1;
        }
    }
    vector<int> res;
    vector<bool> used(n);
    if(st.size() * 2 <=k){
        int rem = k - (int)st.size()*2;
        for(auto x:st){
            auto&p = mp[x];
            res.push_back(p[0]);
            res.push_back(p[1]);
            used[p[0]] = 1;
            used[p[1]] = 1;
            for(int i=2;i<p.size();i++){
                if(rem==0)break;
                res.push_back(p[i]);
                used[p[i]] = 1;
                rem--;
            }
        }
        if(rem!=0){
            rep(i,n){
                if(rem==0)continue;
                if(used[i])continue;
                ll X = a[i];
                for(auto x:st){
                    while(X%x==0){
                        X/=x;
                    }
                }
                if(X==1){
                    used[i] = 1;
                    res.push_back(i);
                    rem--;
                }
            }
            if(rem!=0){
                cout << 0 << endl;
                return 0;
            }
        }
    }else{
        int rem = k;
        if(k%2==0){
            for(auto x:st){
                if(rem==0)break;
                auto&p = mp[x];
                res.push_back(p[0]);
                res.push_back(p[1]);
                rem-=2;
            }
        }else{
            if(flag){
                for(auto x:st){
                    auto&p = mp[x];
                    if(p.size()>2){
                        res.push_back(p[0]);
                        res.push_back(p[1]);
                        res.push_back(p[2]);
                        st.erase(x);
                        rem -= 3;
                        break;
                    }
                }
                for(auto x:st){
                    if(rem==0)break;
                    auto&p = mp[x];
                    res.push_back(p[0]);
                    res.push_back(p[1]);
                    rem-=2;
                }
            }else{
                int mi = 100000000;
                int id = -1;
                set<int> rst;
                rep(i,n){
                    ll X = a[i];
                    int b = 0;
                    set<int> tmp;
                    for(auto x:st){
                        bool fff = 0;
                        while(X%x==0){
                            X/=x;
                            fff = 1;
                        }
                        if(fff){
                            b++;
                            tmp.insert(x);
                        }
                    }
                    if(X==1){
                        if(b>1){
                            if(mi>b){
                                mi = b;
                                id = i;
                                rst = tmp;
                            }
                        }
                    }
                }
                if(2*mi + 1 >k){
                    cout << 0 << endl;
                    return 0;
                }
                res.push_back(id);
                for(auto x:rst){
                    st.erase(x);
                    rem -= 2;
                    auto&p = mp[x];
                    res.push_back(p[0]);
                    res.push_back(p[1]);
                }
                for(auto x:st){
                    if(rem==0)break;
                    auto&p = mp[x];
                    res.push_back(p[0]);
                    res.push_back(p[1]);
                    rem-=2;
                }
            }
        }
    }
    rep(i,k){
        cout << a[res[i]];
        if(i!=k-1)cout << " ";
    }
    cout << "\n";
    return 0;
}
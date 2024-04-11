//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%I64d",&a)
#define Put(a) printf("%I64d\n",a)
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Maxn = 1e6 + 1e3;
const int Mod = 1e9 + 9;
pair<int,int> arr[Maxn];
map<pair<int,int>,int> mp;
map<pair<int,int>,int> deg;
map<pair<int,int>,int> depend;
map<int,int> mark;
set<int,greater<int> > inc;
set<int> decr;
int in[Maxn];
int main(){
    int n;
    cin >> n;
    For(i,0,n){
        cin >> arr[i].F >> arr[i].S;
        mp[arr[i]] = i+1;
    }
    For(i,0,n){
        int x = arr[i].F,y = arr[i].S;
        For(a,-1,2){
            if(mp[Mp(x+a,y-1)]){
                deg[Mp(x,y)]++;
            }
        }
    }
    For(i,0,n){
        int x = arr[i].F,y = arr[i].S;
        if(deg[Mp(x,y)] == 1){
            For(a,-1,2){
                if(mp[Mp(x+a,y-1)]){
                    depend[Mp(x+a,y-1)]++;
                }
            }
        }
    }
    For(i,0,n){
        if(!depend[Mp(arr[i].F,arr[i].S)]){
            inc.insert(i);
            decr.insert(i);
        }
    }
    ll ans = 0;
    int pick = 0;
    while(pick != n){
        int cur,x,y;
        if(pick % 2){
            cur = *(decr.begin());
            x = arr[cur].F,y = arr[cur].S;
        }else{
            cur = *(inc.begin());
            x = arr[cur].F,y = arr[cur].S;
        }
        mark[-1] = 1;
        if(!mark[cur] && !depend[Mp(x,y)]){
            ans *= n;
            ans += cur;
            ans %= Mod;
            mark[cur] = 1;
            For(a,-1,2){
                if(mp[Mp(x+a,y-1)]){
                    if(deg[Mp(x,y)] == 1){
                        depend[Mp(x+a,y-1)]--;
                        if(depend[Mp(x+a,y-1)] == 0 && !mark[mp[Mp(x+a,y-1)]-1]){
                            inc.insert(mp[Mp(x+a,y-1)]-1);
                            decr.insert(mp[Mp(x+a,y-1)]-1);
                        }
                    }
                    
                }
                if(mp[Mp(x+a,y+1)]){
                    deg[Mp(x+a,y+1)]--;
                    if(deg[Mp(x+a,y+1)] == 1 && !mark[mp[Mp(x+a,y+1)]-1]){
                        For(b,-1,2){
                            if(mp[Mp(x+a+b,y)] && !mark[mp[Mp(x+a+b,y)]-1])
                                depend[Mp(x+a+b,y)]++;
                        }
                    }
                }
            }
            pick++;
        }
        inc.erase(cur);
        decr.erase(cur);
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
//typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
bool prime[101010];
vector<li> primes;
int bad [101010];
vector<int> cur;
bool on[101010];
void solve() {
    int n,m;
    scanf("%d",&n);
    prime[0] = prime[1] = false;
    
    memset(prime,-1,sizeof(prime));
    for (int i=2; i<=n; ++i)
        if (prime[i]){
            primes.pb(i);
            if (i * 1ll * i <= n)
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
        }
    primes.push_back(1000000);
    scanf("%d",&m);
    cur.assign(primes.size(),0);
    for(int i=0;i<m;++i){
        char c;
        int a;
        scanf(" %c %d",&c,&a);
        
        if(c == '+'){
            cur.clear();
            if(on[a]){
                printf("Already on\n");
                continue;
            }
            else{
                
                int k = a;
                bool good = true;
                for(int j=0;primes[j]*primes[j]<=k;++j){
                    if(k%primes[j] == 0){
                        if(bad[j]){
                            printf("Conflict with %d\n",bad[j]);
                            k=1;
                            good=false;
                            break;
                        }
                        cur.pb(j);
                        while(k%primes[j] == 0){
                            k/=primes[j];
                        }
                    }
                }
                if(k!=1){
                    int pos = lower_bound(primes.begin(),primes.end(),k) - primes.begin();
                    cur.pb(pos);
                    if(bad[pos]){
                        printf("Conflict with %d\n",bad[pos]);
                        good=false;
                    }
                }
                if(good){
                    printf("Success\n");
                    on[a] = true;
                    for(int i=0;i<cur.size();++i){
                    //  cout<<"bad" << cur[i]<< "a"<<endl;
                        bad[cur[i]] = a;
                    }
                }
            }
        }
        
        else{ //minus
            if(!on[a]){
                printf("Already off\n");
            }
            else{
                on[a] = false;
                int k=a;
                for(int j=0;primes[j]*primes[j]<=k;++j){
                    if(k%primes[j] == 0){
                        bad[j] = 0;
                        while(k%primes[j] == 0){
                            k/=primes[j];
                        }
                    }
                }
                if(k!=1){
                    int pos = lower_bound(primes.begin(),primes.end(),k) - primes.begin();
                    bad[pos] = 0;
                }
                printf("Success\n");
            }
        }
    }
    
    
}
#include <bits/stdc++.h>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vp32 vec;
    int p;
    int val[2*n];
    forn(i,2*n){
        cin >> p;
        val[i]=p;
        vec.pb(mp(p,i+1));
    }
    m32 ma;
    int ab,b;
    forn(i,m){
        cin >> ab >> b;
        ma[ab]=b;
        ma[b]=ab;
    }
    int t;
    cin >> t;
    sort(vec.begin(),vec.end());
    int in=1;
    int a[2*n];
    forn(i,2*n) a[i]=0;
    forn(i,n){
        if(t==2){
            int k;
            cin >> k;
            a[k-1]=1;
            if(ma.find(k)!=ma.end() && a[ma[k]-1]==0){
                cout << ma[k] << ln;
                fflush(stdout);
                a[ma[k]-1] = 1;
                int temp = ma[k];
                ma.erase(ma.find(k));
                ma.erase(ma.find(temp));
            }
            else if(ma.size()>0){
                auto it = ma.begin();
                int in1 = it->fi;
                int in2 = ma[in1];
                if(val[in1-1]<val[in2-1]){
                    cout << in2 << ln;
                    fflush(stdout);
                    a[in2-1]=1;
                }
                else{
                    cout << in1 << ln;
                    fflush(stdout);
                    a[in1-1]=1;
                }
                ma.erase(ma.find(in1));
                ma.erase(ma.find(in2));
            }
            else{
                while(a[vec[2*n-in].se-1]!=0) in++;
                cout << vec[2*n-in].se << ln;
                fflush(stdout);
                a[vec[2*n-in].se-1]=1;
            }
        }
        else{
                if(i==0) {
                    if(ma.size()>0){
                        auto it = ma.begin();
                        int in1 = it->fi;
                        int in2 = ma[in1];
                        if(val[in1-1]<val[in2-1]){
                            cout << in2 << ln;
                            fflush(stdout);
                            a[in2-1]=1;
                        }
                        else{
                            cout << in1 << ln;
                            fflush(stdout);
                            a[in1-1]=1;
                        }
                        ma.erase(ma.find(in1));
                        ma.erase(ma.find(in2));
                    }
                else{
                    cout << vec[2*n-in].se << ln;
                    fflush(stdout);
                    a[vec[2*n-in].se-1]=1;
                }
                }
                else{
                    int k;
                    cin >> k;
                    a[k-1]=1;
                    if(ma.size()>0){
                        auto it = ma.begin();
                        int in1 = it->fi;
                        int in2 = ma[in1];
                        if(val[in1-1]<val[in2-1]){
                            cout << in2 << ln;
                            fflush(stdout);
                            a[in2-1]=1;
                        }
                        else{
                            cout << in1 << ln;
                            fflush(stdout);
                            a[in1-1]=1;
                        }
                        ma.erase(ma.find(in1));
                        ma.erase(ma.find(in2));
                    }
                    else{
                        while(a[vec[2*n-in].se-1]!=0) in++;
                        cout << vec[2*n-in].se << ln;
                        fflush(stdout);
                        a[vec[2*n-in].se-1]=1;
                    }
            }
        }
    }
    if(t==1){
        int k;
        cin >> k;
    }
    return 0;
}
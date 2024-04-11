#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 1e9 + 7;
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
#define INF LLONG_MAX


int main(){
	// ios_base::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
    string t;
    cin >> t;
    string s=t;
    string s1=t,s2=t,s3=t;
    ll n=t.size();
    ll n1=n/26;
    if(n%26!=0) n1++;
    ll n2 = n/676;
    if(n%676!=0) n2++;
    ll n3 = 1;
    forn(i,n){
        s1[i]='a'+((i/n1)%26);
        s2[i]='a'+((i/n2)%26);
        s3[i]='a'+((i/n3)%26);
    }
    string t1,t2,t3;
    forn(i,1){
        cout << "? " << s1 << endl;
        cin >> t1; 
        cout << "? " << s2 << endl;
        cin >> t2; 
        cout << "? " << s3 << endl;
        cin >> t3; 
    }
    forn(i,n){
        forn(j,n){
            if(s1[i]==t1[j] && s2[i]==t2[j] && s3[i]==t3[j]) {s[i]=t[j]; break;}
        }
    }
    cout << "! " << s << endl;
    return 0;
}
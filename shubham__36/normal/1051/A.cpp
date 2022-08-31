//#include <bits/stdc++.h>
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
typedef map<int,int> m32;
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
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int n;
    cin >> n;
    forn(i,n) {
        cin >> s;
        int d=0,l=0,u=0;
        forn(j,s.length()){
            if(s[j]-'0'>=0 && s[j]-'0'<=9 && d==0) d=j+1;
            else if(s[j]-'a'>=0 && s[j]-'a'<=25 && l==0) l=j+1;
            else if(s[j]-'A'>=0 && s[j]-'A'<=25 && u==0) u=j+1;
            if(u!=0 && l!=0 && d!=0) break;
        }
        if(u!=0 && l!=0 && d!=0){
            cout << s << ln;
            continue;
        }
        else if(u!=0 && l!=0 && d==0){
            bool b=false;
            forn(j,s.length()){
                if(j != u-1 && j != l-1 && !b) {cout << "0";b=true;}
                else cout << s[j];
            }
            cout << ln;
            continue;
        }
        else if(u!=0 && l==0 && d!=0){
            bool b=false;
            forn(j,s.length()){
                if(j != d-1 && j != u-1 && !b) {cout << "a";b=true;}
                else cout << s[j];
            }
            cout << ln;
            continue;
        }
        else if(u==0 && l!=0 && d!=0){
            bool b=false;
            forn(j,s.length()){
                if(j != d-1 && j != l-1 && !b) {cout << "A";b=true;}
                else cout << s[j];
            }
            cout << ln;
            continue;
        }
        else if(u!=0 && l==0 && d==0){
                int k=0;
                cout << "a0";
            for(ll j=2;j<s.length();j++){
                cout << s[j];
            }
            cout << ln;
            continue;
        }
        else if(u==0 && l!=0 && d==0){
                int k=0;
                cout << "A0";
            for(ll j=2;j<s.length();j++){
                cout << s[j];
            }
            cout << ln;
            continue;
        }
        else if(u==0 && l==0 && d!=0){
                int k=0;
                cout << "aA";
            for(ll j=2;j<s.length();j++){
                cout << s[j];
            }
            cout << ln;
            continue;
        }
    }
    return 0;
}
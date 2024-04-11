// #include <bits/stdc++.h>
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

int main(){
	// ios_base::sync_with_stdio(0);
 //    // cin.tie(0);
 //    cout.tie(0);
	v32 va(30,-1);
	v32 vb(30,-1);
	ll c=0,d=0;
	int res;
	cout << "? 0 0" << ln;
	fflush(stdout);
	cin >> res;
	int tres,ktres;
	int f=1;
	int used = res;
		forn(i,30){
			if(0 != used){
				ll temp1 = c + pow(2,29-i);
				ll temp2 = d + pow(2,29-i);
				cout << "? " << temp1 << " " << temp2 << ln;
				fflush(stdout);
				cin >> tres;
				if(tres != used){
					if(tres == 1){
						va[i] = 0; vb[i] = 1;
					}
					else if(tres == -1){
						va[i] = 1; vb[i] = 0;
						f = -1;
					}
				}
			}
			if(true){
				ll temp = d + pow(2,29-i);
				cout << "? " << c << " " << temp << ln;
				fflush(stdout);
				cin >> ktres;
				if(va[i]!=-1){
					used = ktres;
				}
				else if(ktres == 1){
					va[i] = 1; vb[i] = 1;
				}
				else{
					va[i] = 0; vb[i] = 0;
				}
			}
			if(va[i]==1) c += pow(2,29-i);
			if(vb[i]==1) d += pow(2,29-i);
		}
		cout << "! " << c << " " << d << ln;
		fflush(stdout);
		return 0;
}
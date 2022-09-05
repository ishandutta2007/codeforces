#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
int gcd(int a,int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s1,s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();
    int ss = 0;
    for(int i = 0;; ++i){
        if (i>=l1 || i>=l2) break;
        if (s1[i]!=s2[i]) break;
        else ss++;
    }
    int res = 0;
    int g = gcd(l1,l2);
    vector<int> z1 = z_function(s1);
    vector<int> z2 = z_function(s2);
    FOR(i,1,g+1)
        if (g%i == 0){
            if ((i==l1 || z1[i] == l1 - i) && (i==l2 || z2[i] == l2 - i) && i<=ss){
                res++;
                //cout << i << endl;
            }
        }
    cout << res << endl;
    return 0;
}
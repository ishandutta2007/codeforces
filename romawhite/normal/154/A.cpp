//#pragma comment(linker, "/STACK:33554432")
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <memory.h>
#include <list>
#include <stack>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,b,a) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define X first
#define Y second
#define MP make_pair

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UInt;
typedef vector<int> VI;

int main(){
    //freopen("d3.in", "r", stdin);
    //freopen("d3.out", "w", stdout);
    string s,s1;
    vector <string> a;
    cin >> s;
    int k;
    cin >> k;
    FOR(i,0,k){
        cin >> s1;
        a.push_back(s1);
        reverse(s1.begin(),s1.end());
        a.push_back(s1);
    }
    int res = 0;
    FOR(i,1,(int)s.size()){
        string s2="";
        s2+=s[i-1];
        s2+=s[i];
        FOR(j,0,2*k)
            if (s2 == a[j])
            {
                int l=i-1;
                while (l>=0 && s[l] == a[j][0]) l--;
                int r = i;
                while (r<s.length() && (s[r] == a[j][1] || s[r]==a[j][0])) r++;
                //cout << i << i-l-1 << r-i << endl;
                int k1=0,k2=0;
                FOR(t,l+1,r)
                    if (s[t] == a[j][0]) k1++;
                    else k2++;
                res+=min(k1,k2);
                i = r;
            }
    }
    cout << res;
    return 0;
}
//#pragma comment(linker,"/STACK:16777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;


int main() {
    /*fstream in("input.txt");
    ofstream out("output2.txt");*/
    string s,s1="",s2="";
    cin >> s;
    bool q=1;
    FOR(i,0,s.length()){
        if (s[i] == ':') q=0;
        else if (q) s1+=s[i];else s2+=s[i];
    }
    vector<int> a;
    vector<int> b;
    for(int i=0;i<s1.size();i++)
        if (s1[i]>='0' && s1[i]<='9')
            a.PB(s1[i]-'0');
        else a.PB(s1[i]-'A'+10);
    for(int i=0;i<s2.size();++i)
        if (s2[i]>='0' && s2[i]<='9')
            b.PB(s2[i]-'0');
        else b.PB(s2[i]-'A'+10);
    int m = 0;
    FOR(i,0,a.size())
        m = max(m,a[i]);
    FOR(i,0,b.size())
        m = max(m,b[i]);
    bool w=0;
    ll r=0,t=0;
    FOR(j,0,a.size())
        r=100*r+a[j];
    FOR(j,0,b.size())
        t=100*t+b[j];
    if (r<24 && t<60) {cout <<"-1";return 0;}
    FOR(i,m+1,60){
        ll r=0,t=0;
        FOR(j,0,a.size())
            r=i*r+a[j];
        FOR(j,0,b.size())
            t=i*t+b[j];
        if (r<24 && t<60) { cout << i << ' '; w=1;}
    }
    if (!w) cout << 0;
    //system("pause");
    return 0;
}
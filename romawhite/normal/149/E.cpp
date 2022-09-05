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

int main() {
    /*fstream in("input.txt");
    ofstream out("output2.txt");*/
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> ss(n);
    FOR(i,0,n)
        cin >> ss[i];
    int res = 0;
    FOR(i,0,n){
        if (ss[i].size()>s.size() || ss[i].size()==1) continue;
        string s1 = ss[i]+"#"+s;
        vector<int> z1 = z_function(s1);
        string s2 = s;
        reverse(ALL(s2));
        string s3 = ss[i];
        reverse(ALL(s3));
        s2 = s3+"#"+s2;
        vector<int> z2 = z_function(s2);
        //reverse(ALL(z2));
        /*FOR(j,0,z1.size())
            cout << z1[j] << ' ';
        cout << endl;
        FOR(j,0,z2.size())
            cout << z2[j] << ' ';
        cout << endl;*/
        int dp1[100100],dp2[100100];
        dp1[0]=z1[ss[i].size()+1];
        //cout << z1[ss[i].size()+2] << ' ' << dp1[0] << endl;
        FOR(j,ss[i].size()+2,z1.size())
            if (z1[j]>dp1[j-ss[i].size()-2]) dp1[j-ss[i].size()-1] = z1[j];
            else dp1[j-ss[i].size()-1] = dp1[j-ss[i].size()-2];
        dp2[0] = z2[ss[i].size()+1];
        for(int j=ss[i].size()+2;j<z2.size();++j)
            if (z2[j]>dp2[j-ss[i].size()-2]) dp2[j-ss[i].size()-1] = z2[j];
            else dp2[j-ss[i].size()-1] = dp2[j-ss[i].size()-2];
        bool qw = 0;
        /*FOR(j,0,s.size())
            cout << dp1[j] << ' ';
        cout << endl;
        FOR(j,0,s.size())
            cout << dp2[j] << ' ';
        cout << endl;*/
        FOR(j,0,s.size()-ss[i].size()+1)
            if (dp1[j]+dp2[s.size()-ss[i].size()-j]>=ss[i].size())
                qw = 1;
        if (qw)
            res ++;
    }
    cout << res;
    //system("pause");
    return 0;
}
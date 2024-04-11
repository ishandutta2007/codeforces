#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
 
using namespace std;
 
#define next fdfdsfdsfdsfdsfds
#define y1 ggvfdg
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define FILL(a,b) memset((a),b,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
#define y1 asdf
 
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int MOD = 1000000007;
const double EPS = 1e-7;

int dp[107][107][107];
pair<pair<int,int> ,int>  p[107][107][107];

int r[107][26];

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    FOR(i,0,107)
        FOR(j,0,107)
            FOR(k,0,107)
                p[i][j][k] = MP(MP(-1,-1) , -1);

    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    FOR(i,0,s3.size() + 1)
        FOR(nx , 0 , 26){
            string t = "";
            FOR(j,0,i)
                t += s3[j];
            t += char('A' + nx);
            FOR(k,0,t.size()){
                bool ok = 1;
                FOR(l,k,t.size())
                    if (t[l] != s3[l - k])
                        ok = 0;
                if (ok) {
                    r[i][nx] = t.size() - k;
                    break;
                }
            }
    }

    FOR(i,0,s1.size())
        FOR(j,0,s2.size())
            FOR(k,0,s3.size()){
                if (dp[i][j][k] > dp[i + 1][j][k]){
                    dp[i + 1][j][k] = dp[i][j][k];
                    p[i + 1][j][k] = p[i][j][k];
                }
                if (dp[i][j + 1][k] < dp[i][j][k]){
                    dp[i][j + 1][k] = dp[i][j][k];
                    p[i][j + 1][k] = p[i][j][k];
                }
                if (s1[i] == s2[j])
                    if (dp[i][j][k] + 1 > dp[i + 1][j + 1][r[k][s1[i] - 'A']]){
                        dp[i + 1][j + 1][r[k][s1[i] - 'A']] = dp[i][j][k] + 1;
                        p[i + 1][j + 1][r[k][s1[i] - 'A']] = MP(MP(i,j) , k);
                    }
    }


    int M = 0;
    int I;
    int J;
    int K;

    

    FOR(i,0,s1.size() + 1)
        FOR(j,0,s2.size() + 1)
            FOR(k,0,s3.size()){
                if (dp[i][j][k] > M){
                    M = dp[i][j][k];
                    I = i;
                    J = j;
                    K = k;
                }
    }
    //cout << I << ' ' << J << ' ' << K << endl;

    if (M == 0){
        cout << 0 << endl;
        return 0;
    }

    string res = "";

    while (I != -1 && J != -1 && K != -1){
        pair<pair<int,int> ,int> t = p[I][J][K];
        I = t.first.first;
        J = t.first.second;
        K = t.second;
        if (I == -1)
            break;
        res += s1[I];
        
    }

    reverse(ALL(res));
    cout << res << endl;

    return 0;
}
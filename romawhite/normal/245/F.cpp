//#pragma comment(linker, "/STACK:32777216")
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
#include <stack>
#include <sstream>
#include <fstream>

 
using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod = 1000000007;

int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

int Min = 60;
int Hour = 60 * Min;
int Day = 24 * Hour;

deque<int> q;

int main() {
    int n,m;
    cin >> n >> m;
    string s1,s2;
    string sss;
    while (cin >> s1 >> s2){
        int mon = 10 * (s1[5] - '0') + s1[6] - '0';
        int day = 10 * (s1[8] - '0') + s1[9] - '0';
        LL sec = 0;
        FOR(i,1,mon){
            sec += month[i - 1] * Day;
        }
        //cout << sec << endl;
        sec += (day - 1) * Day;
        //cout <<sec << endl;
        int h = 10 * (s2[0] - '0') + s2[1] - '0';
        ///cout << sec << endl;
        int mm = 10 * (s2[3] - '0') + s2[4] - '0';
        //cout << sec << endl;
        int s = 10 * (s2[6] - '0') + s2[7] - '0';
        sec += h * Hour;
        sec += mm * Min;
        sec += s;
        getline(cin,sss);
        //cout << sec << endl;
        q.push_back(sec);
        while (q.front() <= sec - n)
            q.pop_front();

        if (q.size() >= m){
            cout << s1 << ' ';
            FOR(i,0,8)
                cout << s2[i];
            cout << endl;
            return 0;
        }

    }

    cout << -1 << endl;

    return 0;
}
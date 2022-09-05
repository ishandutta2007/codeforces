#pragma comment(linker, "/STACK:32000000")
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <time.h>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(LL(i)=(a);i<b;i++)
#define RFOR(i,a,b) for(int(i)=(a-1);i>=b;i--)
#define PI acos(-1.0)
#define MP make_pair
#define PB push_back
#define next htrhtrhtrh
#define ALL(A) A.begin(),A.end()
#define SZ(A) A.size()
#define FILL(a,b) memset(a,b,sizeof(a))
#define CLEAR(a) memset(a,0,sizeof(a))

typedef long long Int;
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 200000;
const int INF = 100000000;
const int MOD = 1000000007;
const double EPS = 1E-7;
const int IT = 10024;

map<int , vector<pair<int,int> > > r;
map<int , vector<pair<int,int> > > c;
map<int,int> R;
map<int,int> C;

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    int k;
    cin >> k;
    FOR(i,0,k){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2);

        if (x1 == x2){
            r[x1].PB(MP(min(y1 , y2) , max(y1, y2)));
        }
        else{
            c[y1].PB(MP(min(x1 , x2) , max(x1, x2)));
        }

    }

    int dr = n - 1 - r.size();
    int dc = m - 1 - c.size();
    int res = 0;
    if (dr & 1)
        res ^= m;
    if (dc & 1)
        res ^= n;

    for(map<int,vector<pair<int,int> > >::iterator it = r.begin(); it != r.end(); ++it){
        int cnt = 0;
        sort(ALL(it->second));
        cnt += it->second[0].first;
        int rigth = it->second[0].second;
        FOR(i,1,it->second.size()){
            cnt += max(0 , it->second[i].first - rigth);
            rigth = max(rigth , it->second[i].second);
        }
        cnt += m - rigth;
        R[it->first] = cnt;
        res ^= cnt;
    }

    for(map<int,vector<pair<int,int> > >::iterator it = c.begin(); it != c.end(); ++it){
        int cnt = 0;
        sort(ALL(it->second));
        cnt += it->second[0].first;
        int rigth = it->second[0].second;
        FOR(i,1,it->second.size()){
            cnt += max(0 , it->second[i].first - rigth);
            rigth = max(rigth , it->second[i].second);
        }
        cnt += n - rigth;
        C[it->first] = cnt;
        res ^= cnt;
    }

    if (res == 0){
        cout << "SECOND\n";
        return 0;
    }
    else{
        cout << "FIRST\n";
    }

    if (dr && (res ^ m) <= m){
        int cut = m - (res ^ m);
        int X;
        FOR(i,1,100007)
            if (!R.count(i)){
                X = i;
                break;
            }
        cout << X << ' ' << 0 << ' ' << X << ' ' << cut << endl;
        return 0;

    }


    if (dc && (res ^ n) <= n){
        int cut = n - (res ^ n);
        int X;
        FOR(i,1,100007)
            if (!C.count(i)){
                X = i;
                break;
            }
        cout << 0 << ' ' << X  << ' ' << cut << ' ' << X << endl;
        return 0;
    }


    for(map<int,int>::iterator it = R.begin(); it != R.end(); ++it){
        if ((res ^ it->second) <= it->second){
            int cut = it->second - (res ^ it->second);
            int x = it->first;

            vector<pair<int,int> > temp = r[x];

            int cnt = 0;
            cnt += temp[0].first;
            if (cut <= temp[0].first){
                cout << x << ' ' << 0 << ' ' << x << ' ' << cut << endl;
                return 0;
            }
            int rigth = temp[0].second;
            FOR(i,1,temp.size()){
                int add = max(0 , temp[i].first - rigth);
                if (cnt + add >= cut){
                    cout << x << ' ' << 0 << ' ' <<  x << ' ' << rigth + cut - cnt << endl;
                    return 0;
                }
                cnt += add;
                rigth = max(rigth , temp[i].second);
            }
            cout << x << ' ' << 0 << ' ' << x << ' ' << rigth + cut - cnt << endl;
            return 0;
        }
    }


    for(map<int,int>::iterator it = C.begin(); it != C.end(); ++it){
        if ((res ^ it->second) <= it->second){
            int cut = it->second - (res ^ it->second);
            int x = it->first;

            vector<pair<int,int> > temp = c[x];

            int cnt = 0;
            if (cut <= temp[0].first){
                cout << 0 << ' ' << x << ' ' << cut << ' ' << x << endl;
                return 0;
            }

            cnt += temp[0].first;
            int rigth = temp[0].second;
            FOR(i,1,temp.size()){
                int add = max(0 , temp[i].first - rigth);
                if (cnt + add >= cut){
                    cout << 0 << ' ' << x << ' ' << rigth + cut - cnt << ' ' << x << endl;
                    return 0;
                }
                cnt += add;
                rigth = max(rigth , temp[i].second);
            }
            cout << 0 << ' ' << x << ' ' << rigth + cut - cnt << ' ' << x << endl;
            return 0;
        }
    }

}
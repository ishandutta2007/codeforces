#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 2000;
const int BASE = 1000000000;

char s[MAX];
int v[MAX];
set<pair<int,int> > S;
int cur = 0;

int p[MAX], cnt[MAX], c[MAX];
int pn[MAX], cn[MAX];


int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%s" , s);
    int n = strlen(s);
    int val = 0;
    FOR(i,0, n)
    {
        if (s[i] == '(')
        {
            ++val;
        }
        else
        {
            --val;
        }
        v[i] = val;
        S.insert(MP(val , i));
    }

    vector<int> ids;
    int M = -INF;
    FOR(it,0,n)
    {
        int V = min(S.begin()->first + cur, 0);
        //cout << S.begin()->first<< ' ' << cur << endl;
        if (V > M)
        {
            ids.clear();
        }
        if (V >= M)
        {
            M = V;
            ids.push_back((n - it) % n);
        }
        int id = n - it - 1;
        S.erase(MP(v[id] , id));
        if (s[id] == '(')
        {
            ++cur;
            v[id] = 1 - cur;
            S.insert(MP(v[id] , id));
        }
        else
        {
            --cur;
            v[id] =  - 1 - cur;
            S.insert(MP(v[id] , id));
        }
    }

    /*cout << M << endl;
    FOR(i,0,ids.size())
    {
        cout << ids[i] << ' ';
    }
    cout << endl;*/

    FILL(cnt, 0);
    FOR(i,0,n)
        ++cnt[s[i] - '('];
    cnt[1] += cnt[0];
    FOR(i,0,n)
        p[--cnt[s[i] - '(']] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]])  ++classes;
        c[p[i]] = classes-1;
    }

    for (int h=0; (1<<h)<n; ++h)
    {
        FOR(i,0,n)
        {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        FILL(cnt, 0);
        for (int i=0; i<n; ++i)
            ++cnt[c[pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i)
        {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
                ++classes;
            cn[p[i]] = classes-1;
        }
        memcpy (c, cn, n * sizeof(int));
    }

    int cl = INF;
    int id;
    FOR(i,0,ids.size())
    {
        if (cn[ids[i]] < cl)
        {
            cl = cn[ids[i]];
            id = ids[i];
        }
    }
    //cout << id << endl;
    string R = "";
    FOR(i,0,abs(M))
    {
        R += '(';
    }
    FOR(i,id,n)
    {
        R += s[i];
    }
    FOR(i,0,id)
    {
        R += s[i];
    }
    val = 0;
    FOR(i,0,R.size())
    {
        if (R[i] == '(')
                ++val;
        else --val;
    }
    FOR(i,0,val)
    {
        R += ')';
    }
    printf("%s" , R.c_str());


    return 0;
}
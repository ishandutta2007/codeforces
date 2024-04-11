#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

string s,w;
vector<int> res;

void norm(int &pos){
    while (s[pos] != '>') pos ++;
    pos ++;
}

void read_table(int &pos);

int read_cell(int &pos){
    norm(pos);
    while (s[pos+1] != '/')
        read_table(pos);
    norm(pos);  
    return 1;
}   
int read_row(int &pos){
    int now = 0;
    norm(pos);
    while (s[pos+1] != '/'){
        now += read_cell(pos);
    }
    norm(pos);
    return now;
}   
void read_table(int &pos){
    int now = 0;
    norm(pos);
    while (s[pos+1] != '/'){
        cerr << pos <<" " << s[pos] << " " << s[pos+1] << endl;
            now += read_row(pos);
    }
    norm(pos);
    res.pb(now);
}   




int main ()
{

    while (cin >> w)s += w;
    s += ">>>";
    int now = 0;
    read_table(now);
    sort(all(res));
    forn(i, res.size())
        cout << res[i] << " ";
    cout << endl;               
    
    
    return 0;
}
#include<map>
#include<cstring>
#include<set>
#include<string>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<ctype.h>
#include<fstream>
#include<string.h>
#include<cstdio>
#include<math.h>
#include<stack>
#include<queue>
#include<ctime>
//#include<conio.h>
using namespace std;

const int INF_MAX=0x7FFFFFFF;
const int INF_MIN=-(1<<30);

const double eps=1e-10;
const double pi=acos(-1.0);

#define MP make_pair
#define PB push_back   //a.pb( )
#define chmin(a,b) ((a)<(b)?(a):(b))
#define chmax(a,b) ((a)>(b)?(a):(b))


template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){
    while (!Q.empty()) Q.pop();}
inline int random(int l, int r){return rand() % (r - l + 1) + l;}

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int dir_4[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int dir_8[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
//

//******* WATER ****************************************************************

const int maxn = 200010;
double val[maxn], add[maxn];

int main() {
    memset(val, 0, sizeof(val));
    memset(add, 0, sizeof(add));
    double sum = 0;
    int n;
    int last = 1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int choose;
        cin >> choose;
        if(choose == 1) {
            int a;
            double x;
            cin >> a >> x;
            add[a] += x;
            sum += a*x;
        }
        else if(choose == 2) {
            last++;
            double a;
            cin >> a;
            val[last] = a;
            sum += a;
        }
        else if(choose == 3) {
            sum -= (val[last] + add[last]);
            add[last-1] += add[last];
            add[last] = 0;
            val[last] = 0;
            last--;
        }
       // cout << "... " << sum << " " << last << endl;
        printf("%.20lf\n", sum/(last));
    }
    return 0;
}
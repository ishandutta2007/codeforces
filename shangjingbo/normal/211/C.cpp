#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double a,double b){x=a;y=b;}
    inline double norm(){return sqrt(sqr(x)+sqr(y));}
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
//==============================================================================================

const int maxn  =   105;

long long f[maxn][2][2][3];

int main()
{
    string t,s;
    cin >> t;
    //for (int i=0;i<100;++i)
//      t+='A'+rand()%2;
    //cout << t << endl;
    bool ok=false;
    for (int i=0;i<t.size();++i)
    if (t[i]=='B'){
        s="";
        for (int j=0;j<t.size();++j)
            s+=t[(i+j)%t.size()];
        ok=true;
        break;
    }
    if (!ok){
        puts("1");
        return 0;
    }

    int n=s.size();
    
    f[1][s[0]-'A'][s[0]-'A'][2]=1;
    for (int i=1;i<n;++i){
        for (int st=0;st<2;++st)
            for (int la=0;la<2;++la)
                for (int la2=0;la2<=2;++la2){
                    //swap s[i],s[i-1]
                    if (la==1 && s[i-1]=='B' && s[i]=='A'){
                        if (i>1){
                            f[i+1][st][1][0]+=f[i][st][la][la2];
                        }else{
                            f[i+1][0][1][0]+=f[i][st][la][la2];
                        }
                    }
                    //forbid AB--la=1 la2=0
                    if (i>=2 && la==s[i-1]-'A' && la2==s[i-2]-'A' && la==1 && la2==0) continue;
                    f[i+1][st][s[i]-'A'][la]+=f[i][st][la][la2];
                }
    }
    
    long long ans=0;
    for (int st=0;st<2;++st)
        for (int la=0;la<2;++la)
            for (int la2=0;la2<=2;++la2)if (f[n][st][la][la2]){
                if (s[0]-'A'==st && s[n-1]-'A'==la){
                    if (st==0 && la==1){
                        ans+=f[n][st][la][la2];
                    }
                }
                
                if (n>=2 && la==s[n-1]-'A' && la2==s[n-2]-'A' && la==1 && la2==0) continue;
                if (la==s[n-1]-'A' && s[0]-'A'==st && la==0 && st==1) continue;
                ans+=f[n][st][la][la2];
            }
    cout << ans << endl;
    
    return 0;
}
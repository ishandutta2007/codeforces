#include <bits/stdc++.h>
using namespace std; 
  
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
  
double EPS = 1e-9;      
int INF = 1000000005; 
long long INFF = 1000000000000000005LL; 
double PI = acos(-1); 
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 }; 
  
#ifdef TESTING 
#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#else 
#define DEBUG 
#define VALUE(x) 
#define debug(...) 
#endif 

#define tezi                ios_base::sync_with_stdio(false);\
                            cin.tie(0);\
                            cout.tie(0);        
#define endl                "\n"  
#define FOR(a, b, c)        for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c)       for (int(a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c)       for (int(a) = (b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c)      for (int(a) = (b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c)       for (char(a) = (b); (a) <= (c); ++(a)) 
#define FOREACH(a, b)       for (auto&(a) : (b)) 
#define rep(i, n)           FOR(i, 0, n) 
#define repn(i, n)          FORN(i, 1, n) 
#define MAX(a, b)           a = max(a, b) 
#define MIN(a, b)           a = min(a, b) 
#define SQR(x)              ((ll)(x) * (x)) 
#define RESET(a, b)         memset(a, b, sizeof(a)) 
#define fi                  first 
#define se                  second 
#define mp                  make_pair 
#define pb                  push_back 
#define ALL(v)              v.begin(), v.end() 
#define ALLA(arr, sz)       arr, arr + sz 
#define SIZE(v)             (int)v.size() 
#define SORT(v)             sort(ALL(v)) 
#define REVERSE(v)          reverse(ALL(v)) 
#define SORTA(arr, sz)      sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz)   reverse(ALLA(arr, sz)) 
#define PERMUTE             next_permutation 
#define tc(t)               while (t--)

int n,m;
int k[200005];
pii dt[200005];

bool possible(int d){
    pii micro[n];
     FOR(i,0,n){
         micro[i].fi=-1;
         micro[i].se=i;
     }
    for(int i=0;i<m;i++){
        if(dt[i].fi<=d){
            micro[dt[i].se-1].fi=max(micro[dt[i].se-1].fi,dt[i].fi);
        }
    }
    int temp=0,temp_2=0,prev=0;
    sort(micro,micro+n);
  //  FOR(i,0,n)cout<<micro[i]<<" ";cout<<"\n";
    FOR(i,0,n){
        if(micro[i].fi==-1)temp+=(2*k[micro[i].se]);
        else{
            temp_2 += (micro[i].fi-prev);
            if(temp_2 < k[micro[i].se]){
                temp += temp_2;
                temp += (2*(k[micro[i].se]-temp_2));
                temp_2 = 0;
            }else{
                temp_2 -= k[micro[i].se];
                temp += k[micro[i].se];
            }
            prev = micro[i].fi;
        }
    }//cout<<temp;
    if(temp <= d)return 1;
    else return 0;

}

int binarySearch( int l, int r) 
{ 
  //  cout<<l<<" "<<r<<"\n";
    if ( r - l >1 ) { 
        int mid = (l+r)/2; 
        if(possible(mid)) r=mid;
        else l=mid;
        return binarySearch( l , r); 
    }
    return l+1; 
} 


int main(){
    tezi
    int maxans=0;
    cin>>n>>m;
    FOR(i,0,n){cin>>k[i];maxans+=(2*k[i]);}
    FOR(i,0,m)cin>>dt[i].fi>>dt[i].se;
  //  cout<<possible(21);
   // cout<<maxans;
    cout<<binarySearch(0,maxans);
    return 0;
}
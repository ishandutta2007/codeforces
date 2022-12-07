#include<bits/stdc++.h>
using namespace std;

//MARCOS://N

typedef     long long int   ll ;
typedef     long double     ld ;
typedef     pair<int, int>  pii ;
typedef     vector<int>     vi ;
typedef     vector<vi>      vvi ;
#define     MAX             1000001
#define     x               first
#define     y               second
#define     presents(c,x)   ((c).find(x) != (c).end())
#define     cpresent(c,x)   (find(all(c),x) != c.end())
#define     sz(a)           int((a).size())
#define     pb              push_back
#define     all(c)          (c).begin(),(c).end()
#define     tr(c,i)         for(typeof(c).begin() i=(c).begin(); i!=(c).end(); i++)
#define     mem(p)          memset(p,0,sizeof(p))
#define     memf(p)         memset(p,0x3f,sizeof(p))
#define     memn(p)         memset(p,-1,sizeof(p))
#define     Aninda          ios_base::sync_with_stdio(0);
#define     Sarker          cin.tie(NULL);

 
//ll a[MAX],k(0);


/*
//        <  ### Time ### >

clock(){
  
  clock_t c0 , c1 ;
  time_t t0, t1;
  
  t0 = time(NULL) ;
  c0 = clock() ;
  
  t1 = time(NULL) ;
  c1 = clock();
  
  cout<<"t= "<<(long)(t1-t0)<<endl;
  cout<<"c= "<<(double)(c1-c0)<<endl;

}

//        < ### \Time ### >
*/






// algo _ imp :        < ### Starts Here ### > 

/*
void SieveOfEratosthenes(int n)
{
    bool prime[n+1];  memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++){ if (prime[p] == true){ for (int i=p*2; i<=n; i += p) prime[i] = false; } }
    for (int p=2; p<=n; p++) {if (prime[p]) a[k++]=p; }
}
ll gcd(ll a,ll b)
{  a=abs(a); b=abs(b); if(b==0) {return a;} else { gcd(b,a%b);}   }

pii extendedEuclid(int a, int b) { // returns x, y | ax + by = gcd(a,b)
  if(b == 0) return pii(1, 0);
  else { pii d = extendedEuclid(b, a % b); return pii(d.y, d.x - d.y * (a / b)); }
}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll factorial(int n)
{ ll ans =1;  for(int i=1;i<=n;i++){ans*=i;}  return ans; }

ll nCr( ll n, ll k )
{
    if (k > n){ return 0; }
    if (k * 2 > n){ k = n-k; }
    if (k == 0){ return 1; }
    ll result = n;
    for( ll i = 2; i <= k; ++i ) { result *= (n-i+1); result /= i; }
    return result;
}

ll countDivisor(ll n) {
  ll divisor = 1;
  for (ll i = 0; i < sqrt(n); i++) {  if(n % a[i] == 0) { ll cnt = 1; while (n % a[i] == 0) { n /= a[i]; cnt++;} divisor *= cnt; }  }
  return divisor;
}

int binarySearch(int arr[], int value, int left, int right) {
      while (left <= right) { int middle = (left + right) / 2;
            if (arr[middle] == value) {return (middle+1);}
            else if (arr[middle] > value) {right = middle - 1;}
            else {left = middle + 1;}
            }
      return -1;
}
*/   

//  < ###  Algo _ imp Ends Here ### > 






// templates :  < ### Starts Here ### > 

/*
template <typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v) {
  for(auto &it : v) out << it << ' ';
  return out;
}
template <typename T>
inline istream &operator>>(istream &in, vector<T> &v) {
  for(auto &it : v) in >> it;
  return in;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &out, const pair <T1, T2> &p) {
    out << p.first << ' ' << p.second << ' ';
    return out;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &in, pair <T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
inline ostream &operator<<(ostream &out, const set <T> &p) {
    for(auto &i : p) out << i << ' ';
    return out;
}
template <typename T>
inline istream &operator>(istream &in, T &p) {
    return in >> p;
}
template <typename T>
inline ostream &operator<(ostream &out, const T &p) {
    return out << p;
}
template <typename T1, typename T2>
inline pair<T1&,T2&> unzip_pair(T1 &p1, T2 &p2){return pair<T1&,T2&>(p1,p2);}

template <typename T>
inline bool umin(T &a, const T &b) {return a > b? a = b, 1: 0;}

template <typename T>
inline bool umax(T &a, const T &b) {return a < b? a = b, 1: 0;}
*/

// < ### Template Ends Here ### > 




//  < ### File ### >
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/
//  < ### /File ### >



//cin.ignore(numeric_limits<streamsize>::max(), '\n') //ignore spaces, use new line as delimiter;

int main()
{
    ld n , h ;
    long long x[5000];
    cin >> n >> h ;

    for(int i=1; i<n; i++){
        cout << setprecision(12) << sqrt(i/n) * h << " ";
        x[i%5000] +=i;
    }

    return 0 ;

}
/* Author : Sumeet.Varma
   Trying to move to c++ from java
*/

#include <bits/stdc++.h>

#define fastInput ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define FILL(X, value) memset(X,value,sizeof(X))

using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;

const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int a,int b){ while(b != 0){ int t = b; b = a%b; a = t; } return a;}

void debug(int* a, int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}

void debug(vector<int> b, int n){
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << '\n';
}

const int N = 200009;
int n;
ll a[N];

class CHT // Convex hull trick
{
    typedef long long fft;
    typedef long long retlls;
    typedef long long retll;

    public:
      CHT(){
    }

    struct line_segment
    {
        fft a, b;
        double xLeft;

        enum Type {line, maxQuery, minQuery} type;
        retlls val;

        explicit line_segment(fft aa=0, fft bb=0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}
        retll valueAt(retlls x) const { return a*x+b; }
        friend bool dont_meet(const line_segment& l1, const line_segment& l2) { return l1.a==l2.a; }
        friend double meet(const line_segment& l1, const line_segment& l2) { return dont_meet(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }
        bool operator<(const line_segment& l2) const
        {
            if (l2.type == line)
                return this->a     < l2.a;
            if (l2.type == maxQuery)
                return this->xLeft < l2.val;
            if (l2.type == minQuery)
                return this->xLeft > l2.val;
        }
    };

    bool  isMax = true;
    std::set<line_segment>  slopes;

    bool hasPrev(std::set<line_segment>::iterator it) { return it!=slopes.begin(); }
    bool hasNext(std::set<line_segment>::iterator it) { return it!=slopes.end() && std::next(it)!=slopes.end(); }

    bool bad(const line_segment& l1, const line_segment& l2, const line_segment& l3) { return meet(l1,l3) <= meet(l1,l2); }
    bool bad(std::set<line_segment>::iterator it)
    {
        return hasPrev(it) && hasNext(it)
               && (    isMax && bad(*std::prev(it), *it, *std::next(it))
                       || !isMax && bad(*std::next(it), *it, *std::prev(it)) );
    }

    std::set<line_segment>::iterator fix(std::set<line_segment>::iterator it)
    {
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it))
            return it;

        double val = meet(*it, isMax?*std::prev(it):*std::next(it));
        line_segment buf(*it);
        it = slopes.erase(it);
        buf.xLeft = val;
        it = slopes.insert(it, buf);
        return it;
    }

    void insert_Line(fft a, fft b)
    {
        line_segment l3 = line_segment(a, b);
        auto it = slopes.lower_bound(l3);

        if (it!=slopes.end() && dont_meet(*it, l3))
        {
            if (isMax && it->b < b || !isMax && it->b > b)
                it = slopes.erase(it);
            else
                return;
        }

        it = slopes.insert(it, l3);
        if (bad(it)) { slopes.erase(it); return; }

        while (hasPrev(it) && bad(std::prev(it))) slopes.erase(std::prev(it));
        while (hasNext(it) && bad(std::next(it))) slopes.erase(std::next(it));

        it = fix(it);
        if (hasPrev(it))
            fix(prev(it));
        if (hasNext(it))
            fix(next(it));
    }

    retll evaluate(retlls x) const
    {
        if(slopes.empty())
            return (long long)1e18;
        line_segment q;
        q.val = x;
        q.type = isMax ? line_segment::Type::maxQuery : line_segment::Type::minQuery;

        auto bestLine = slopes.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->valueAt(x);
    }
};

ll ans = 0, oth = 0;
ll p[N];
CHT cht1, cht2;

int main(){

    fastInput;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
        ans += i * a[i];

    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    for(int i = n - 1; i >= 1; i--){
        cht1.insert_Line(i+1,-p[i+1]);
        ll now = cht1.evaluate(a[i]);
        ll pro = i * a[i] -  p[i];
        now -= pro;
        if(now > oth)
            oth = now;
    }

    for(int i = 2; i <= n; i++){
        cht2.insert_Line( (i-1) , -p[i-2] );
        ll now = cht2.evaluate(a[i]);
        ll pro = p[i - 1] - i * 1LL * a[i];
        now += pro;
        if(now > oth)
            oth = now;
    }

    cout << ans + oth << endl;
    return 0;
}
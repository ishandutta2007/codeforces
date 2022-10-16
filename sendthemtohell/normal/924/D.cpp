/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
const int _ML = 228;

const char _inpf[] =
#if defined(ANDREIKKAA)
        "input.txt"
#else
""
#endif
;
const char _outf[] =
#if defined(ANDREIKKAA)
        ""
#else
""
#endif
;

#if defined(ANDREIKKAA)
#undef NDEBUG
#else
#pragma GCC optimize("O3,no-stack-protector")
#endif
#include <bits/stdc++.h>
#if !defined(ANDREIKKAA)
#define endl '\n'
#endif
#define x first
#define y second
using namespace std;
#define rand abcdefghijklmnopqrstuvwxyz
#define random_shuffle abcdefghijklmnopqrstuvwxyz
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef double ld;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);
#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; assert(_ptr < _ML * 1024 * 1024); return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif
template<class T, class U> inline ostream &operator<< (ostream &, const pair<T, U> &);
template<class T, class U> inline istream &operator>> (istream &, pair<T, U> &);
template<class T> inline ostream &operator<< (ostream &, const vector<T> &);
template<class T> inline istream &operator>> (istream &, vector<T> &);
template<class T> inline ostream &operator<< (ostream &, const set<T> &);
template<class T> inline ostream &operator<< (ostream &, const multiset<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_set<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_multiset<T> &);
template<class T, class U> inline ostream &operator<< (ostream &, const map<T, U> &);
template<class T, class U> inline ostream &operator<< (ostream &, const unordered_map<T, U> &);

/* ________ CODE ________ */

struct her
{
    ll x, v;
    int num;
};

const int N = 200 * 1000 + 228;
int t[N];

ll w;

bool cmp_mn(const her&, const her&);

bool cmp_pl(const her &a, const her &b)
{
    if(abs(a.x) * abs(b.v + w) == abs(b.x) * abs(a.v + w))
    {
        if(w == 0)
        {
            return a.num < b.num;
        }
        return cmp_mn(a, b);
    }
    return abs(a.x) * abs(b.v + w) < abs(b.x) * abs(a.v + w);
};

bool cmp_mn(const her &a, const her &b)
{
    if(abs(a.x) * abs(b.v - w) == abs(b.x) * abs(a.v - w))
    {
        if(w == 0)
        {
            return a.num < b.num;
        }
        return cmp_pl(a, b);
    }
    return abs(a.x) * abs(b.v - w) > abs(b.x) * abs(a.v - w);
};

ll get_t(int x)
{
    ll sum = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
    {
        sum += t[x];
    }
    return sum;
}

void upd_t(int x)
{
    for(; x < N; x |= (x + 1))
    {
        ++t[x];
    }
}

int solve(vector<her> a)
{
    int n = sz(a);
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(a[i].x - a[j].x == 0)
            {
                continue;
            }
            
            ld ww = (a[i].x * a[j].v - a[j].x * a[i].v) / (ld)(a[i].x - a[j].x);
            if(abs(ww) <= w)
            {
                ++ans;
            }
        }
    }
    
    return ans;
}

inline void _main_function()
{
    //for(int cnt = 0; cnt < 1000; ++cnt)
    //{
        //memset(t, 0, sizeof(t));
        int n;
        cin >> n >> w;
        //n = 2;
        //w = 2;
        
        vector<her> a(n), b(n);
        for(int i = 0; i < n; ++i)
        {
         /*   hui:;
            a[i].x = rd() % 10 + 1;
            a[i].v = rd() % 5 + 3;
            if(rd() & 1)
            {
                a[i].x *= -1;
            }
            else
            {
                a[i].v *= -1;
            }
            
            for(int j = 0; j < i; ++j)
            {
                if(a[i].x == a[j].x && a[i].v == a[j].v)
                {
                    goto hui;
                }
            }
            
            cout << a[i].x << " " << a[i].v << endl;*/
            
            cin >> a[i].x >> a[i].v;
            a[i].num = i;
        }
        b = a;
    
        sort(all(a), cmp_pl);
        sort(all(b), cmp_mn);
    
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; ++i)
        {
            v[a[i].num].x = i;
            v[b[i].num].y = i;
        }
    
        sort(all(v));
    
        ll ans = 0;
        for(int i = 0; i < n; ++i)
        {
            ans += get_t(v[i].y);
            upd_t(v[i].y);
        }
    cout << ans << endl;
        //cout << ans << " === " << solve(a) << endl;
        //assert(ans == solve(a));
    //}
}

/* ________ CODE ________ */

int main()
{
#if defined(ANDREIKKAA)
    time_t _start = clock();
#endif
    if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
    if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cout << setprecision(20);
    //cout << fixed;
    
    _main_function();
#if defined(ANDREIKKAA)
    cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}

template<class T, class U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p)
{
    _out << _p.x << ' ' << _p.y;
    return _out;
}
template<class T, class U> inline istream &operator>> (istream &_in, pair<T, U> &_p)
{
    _in >> _p.x >> _p.y;
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const vector<T> &_v)
{
    if (_v.empty()) { return _out; }
    _out << *_v.begin();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline istream &operator>> (istream &_in, vector<T> &_v)
{
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const set<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m)
{
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m)
{
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
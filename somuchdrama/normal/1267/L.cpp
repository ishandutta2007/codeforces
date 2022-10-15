#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...)
#endif
struct init{init(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
#endif // LOCAL
cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

char ans[1001][1001];

#define endl "\n"
int32_t main(){

    ll n, l, k;
    cin >> n >> l >> k;
    string ss;
    cin >> ss;
    vector<char> s(ss.size());
    for (int i = 0; i < ss.size(); i++) s[i] = ss[i];
    sort(s.begin(), s.end());
    if (k == 1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < l; j++){
                cout << s[i * l + j];
            }
            cout << endl;
        }
        return 0;
    }
    ll r = 0;
    ll i = 0;

    vector<ll> poh(k);
    ll nw = 0;
    while (r < l){
        for (; i < n * l; i++){
            if (!poh[i % k]){
                ans[i % k][r] = s[nw];
                nw++;
                if ((i % k) && ans[i % k][r] > ans[i % k - 1][r]){
                    poh[i % k - 1] = 1;
                }
            }
            if (i % k == (k - 1)) {

                    for (int j = 0; j < k; j++){
                        if (ans[j][r] < ans[k - 1][r]) poh[j] = 1;
                    }

                    i++; break;}
        }
        if (ans[k - 1][r] > ans[k - 2][r]){
            r++;
            break;
        }
        r++;
    }
    for (int j = r; j < l; j++){
        ans[k - 1][j] = s[nw];
        nw++;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < l; j++){
            if (ans[i][j] == 0){
                ans[i][j] = s[nw++];
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < l; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }


    return 0;
}
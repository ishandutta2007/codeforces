#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 3;

ll a[N], b[N], dp[N];
int n;

struct ConvexHullTrick{
    struct Line{
        ll a, b;
        Line(){}
        Line(ll a, ll b): a(a), b(b){}
    };
    vector<Line> lines;
    int ptr;

    inline ll eval(Line l, ll x){
        return l.a * x + l.b; 
    }
    ConvexHullTrick(){
        ptr = 0;
    }
    long double intersect(Line l1, Line l2){
        return (long double)(l2.b - l1.b) / (l1.a - l2.a);
    }
    bool bad(Line l){
        //return (__int128)(lines[lines.size() - 2].b - l.b) * (lines[lines.size() - 2].a - lines.back().a) > (__int128)(lines.back().b - lines[lines.size() - 2].b) * (l.a - lines[lines.size() - 2].a); 
        return intersect(l, lines[lines.size() - 2]) < intersect(lines[lines.size() - 2], lines.back());
    }
    void add_line(Line l){
        while(lines.size() >= 2 && bad(l))
            lines.pop_back();
        if(ptr >= lines.size()) ptr = max(0, (int)lines.size() - 1);
        lines.push_back(l);
    }
    ll query(ll x){
        while(ptr != (int)lines.size() - 1 && eval(lines[ptr], x) >= eval(lines[ptr + 1], x))
            ++ptr;
        return eval(lines[ptr], x);
    }
}cht;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    dp[n] = 0;
    for(int i = n - 1; i >= 1; --i){
        cht.add_line(ConvexHullTrick::Line(a[i + 1], dp[i + 1]));
        dp[i] = cht.query(b[i]); 
    }
    cout << dp[1] << "\n";
}
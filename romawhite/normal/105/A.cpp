#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n,m,k,l;
    double kk;
    string s;
    vector <pair<string,int>> a;
    cin >> n >> m >> kk;
    k=int(kk*100+1e-8);
    FOR(i,0,n){
        cin >> s >> l;
        l=(l*k)/100;
        if (l>=100) a.PB(MP(s,l));
    }
    FOR(i,0,m){
        cin >> s;
        a.PB(MP(s,0));
    }
    sort(a.begin(),a.end());
    int res=1;
    FOR(i,0,a.size()-1)
        if (a[i].first!=a[i+1].first)
            res++;
    cout << res << endl;
    FOR(i,0,a.size()-1)
        if (a[i].first!=a[i+1].first)
            cout << a[i].first << ' ' << a[i].second << endl;
    cout << a[a.size()-1].first << ' ' << a[a.size()-1].second << endl;
    //system("pause");
}
//#pragma comment(linker,"/STACK:16777216")
    #include <iostream>
    #include <vector>
    #include <set>
    #include <cstdio>
    #include <cmath>
    #include <string>
    #include <algorithm>
    #include <map>
    #include <queue>

    using namespace std;

    #define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
    #define MP make_pair
    #define ALL(a) ((a).begin(),(a).end())
    #define PB push_back
    #define PII pair<int,int>
    #define CLEAR(a) memset((a),0,sizeof((a)))
    #define X first
    #define Y second

    typedef long long ll;
    typedef unsigned long long ull;
    typedef vector<int> VI;

    const long double pi=3.14159265358979323846264338327950288419716939937510;
    const int INF=2000000000;

    int main(){
        int n;
        long double R,r;
        cin>>n>>R>>r;
        if (r>R) {cout<<"NO";return 0;}
        if (n==1)
            if (R>=r) {
                cout<<"YES";
                return 0;
            }
            else {
                cout<<"NO";
                return 0;
            }
        if (2*r>R) {cout<<"NO";return 0;}
        long double a=asin(r/(R-r));
        long double k=pi/a+0.000000001;
        int l=k;
        if (l>=n) cout<<"YES"; else cout<<"NO";
        //system("pause");
        return 0;
    }
#include<iostream>
#include<cmath>
#include<limits>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<deque>
#include<sstream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
#define max(a,b) ( (a) > (b) ? (a) : (b) )
#define min(a,b) ( (a) < (b) ? (a) : (b) )
#define abs(a)   ( (a) > 0 ? (a) : -(a) )
#define _for_(T, var, start, stop) for(T var = start; var < stop; var++)

#define SQR(n) n*n
typedef long long ll;
typedef unsigned long long ull;
static const double PI = 3.141592653589;


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int mn = n;
    for (int i = 0; i < n; i++){
        vector<int>::iterator upp = upper_bound(v.begin() + i, v.end(), 2*v[i]);
        int l = v.end() - upp;
        mn = min(l+i, mn);
    }
    cout << mn;
}
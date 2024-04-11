#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> P;

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        map<P, int> mp;
        int d[2]{0};
        for(int i = 0; i < n; i++){
            if(s[i] == 'D') d[0]++;
            else d[1]++;
            mp[P(d[0] / gcd(d[0], d[1]), d[1] / gcd(d[0], d[1]))]++;
            cout << mp[P(d[0] / gcd(d[0], d[1]), d[1] / gcd(d[0], d[1]))] << " ";
        }
        cout << endl;
    }
}
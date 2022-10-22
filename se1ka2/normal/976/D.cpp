#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int d[305];
    d[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    int j = n, k = 1, i = 0;
    vector<P> v;
    while(j >= k){
        int l = i + d[k] - d[k - 1];
        for(; i < l; i++){
            for(int m = i + 1; m <= d[j]; m++) v.push_back(P(i, m));
        }
        j--;
        k++;
    }
    cout << (int)v.size() << endl;
    for(P p : v) cout << p.first + 1 << " " << p.second + 1 << endl;
}
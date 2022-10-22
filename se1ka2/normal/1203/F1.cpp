#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, r;
    cin >> n >> r;
    int a[102], b[102];
    priority_queue<P, vector<P>, greater<P>> quep;
    priority_queue<P, vector<P>, greater<P>> quen;
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if(b[i] > 0) quep.push(P(a[i], b[i]));
        else{
            quen.push(P(a[i] + b[i], -b[i]));
            s += -b[i];
        }
    }
    while(quep.size()){
        P np = quep.top();
        quep.pop();
        if(np.first > r){
            cout << "NO" << endl;
            return 0;
        }
        r += np.second;
    }
    r -= s;
    while(quen.size()){
        P np = quen.top();
        quen.pop();
        if(max(0, np.first) > r){
            cout << "NO" << endl;
            return 0;
        }
        r += np.second;
    }
    cout << "YES" << endl;
}
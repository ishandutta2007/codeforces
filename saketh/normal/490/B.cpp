#include <iostream>
#include <map>
#include <set>
using namespace std;

int N, x, y;
map<int, int> b2, a2;
set<int> p;
int q[200005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        b2[x] = y;
        a2[y] = x;
        
        p.insert(y);
        p.insert(x);
    }

    for(map<int, int>::iterator it = b2.begin(); it!=b2.end(); it++)
        p.erase(it->second);

    for(int v = 0, i = -1; b2[v]; ) q[i+=2] = (v = b2[v]);
    for(int v = *p.begin(), i=-2; v!=0; v = b2[v]) q[i+=2] = v;

    for(int i=0; i<N; i++)
        cout << q[i] << " ";
    cout << endl;
    return 0;
}
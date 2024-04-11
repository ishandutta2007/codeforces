#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int a[100002];
    P p[100002];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(a[i], i * 2 + 1);
    }
    sort(p, p + n, greater<P>());
    int l[200002] {0};
    for(int i = 0; i < p[0].first; i++) l[i] = p[i].second;
    for(int i = 0; i < p[0].first; i++){
        if(l[i + p[i].first] == 0) l[i + p[i].first] = p[i].second + 1;
        else cout << l[i + p[i].first - 1] << " " << p[i].second + 1 << endl;
    }
    for(int i = 0; i < n * 2; i++){
        if(l[i + 1] == 0) break;
        cout << l[i] << " " << l[i + 1] << endl;
    }
    for(int i = p[0].first; i < n; i++){
        if(p[i].first == 1){
            cout << l[0] << " " << p[i].second << endl;
            cout << p[i].second << " " << p[i].second + 1 << endl;
        }
        else{
            cout << l[0] << " " << p[i].second << endl;
            cout << l[p[i].first - 2] << " " << p[i].second + 1 << endl;
        }
    }
}
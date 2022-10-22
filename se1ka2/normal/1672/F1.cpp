#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

vector<int> v[200005];
P p[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[200005];
        for(int i = 0; i < n; i++){
            cin >> b[i];
            b[i]--;
            v[b[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) p[i] = P(v[i].size(), i);
        sort(p, p + n, greater<P>());
        int a[200005];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p[i].first; j++){
                if(i < n - 1 && j < p[i + 1].first) a[v[p[i].second][j]] = p[i + 1].second;
                else a[v[p[i].second][j]] = p[0].second;
            }
        }
        for(int i = 0; i < n; i++) cout << a[i] + 1 << " ";
        cout << "\n";
        for(int i = 0; i < n; i++) v[i].clear();
    }
}